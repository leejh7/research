#include "position_move.h"
#include "count_violations.h"
#include <iostream>
using namespace std;

extern vector<vector<int> > incoming_graph, outgoing_graph;

void rotate(vector<int> &arr, int start, int end)
{
    int temp = arr[end], p;
    for (p = end; p > start; p--)
    {
        arr[p] = arr[p - 1];
    }
    arr[p] = temp;
}

void positionMove(vector<int> result, const string description) {
    bool updated = true;
    int prev_cnt = count_violations(result);

    int cur_cnt, n = result.size();
    int min;

    while (updated)
    {
        updated = false;
        for (int i = 0; i < n; i++)
        {
            vector<int> copy_result(result);
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                    rotate(copy_result, j, i);
                else
                    swap(copy_result[j], copy_result[j - 1]);

                if(j<i) {
                    cur_cnt = left_cnt(copy_result, j, i);
                } else {
                    cur_cnt = right_cnt(copy_result, i, j);
                }

                if(cur_cnt < 0) {
                    updated = true;
                    copy(copy_result.begin(), copy_result.end(), result.begin());       
                }
            }
            if(updated) {
                break;
            }
        }
    }


    if(description == "GO") {
        cout << "GO-PM ";
    } else if (description == "WP") {
        cout << "WP-PM ";
    }
    
    cout << count_violations(result) << '\n';
}