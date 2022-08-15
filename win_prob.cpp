#include "win_prob.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

extern vector<vector<int> > incoming_graph, outgoing_graph;

int count_violations(vector<WinProb> &result)
{
    int cnt = 0;
    for (int i = 0; i < result.size(); i++)
    {
        int node = result[i].v;
        for (int j = i + 1; j < result.size(); j++)
        {
            for (int k = 0; k < incoming_graph[node].size(); k++)
            {
                if (result[j].v == incoming_graph[node][k])
                    cnt++;
            }
        }
    }
    return cnt;
}

void winProb() {
    vector<WinProb> result;

    int n = incoming_graph.size();

    for (int i = 0; i < n; i++)
    {
      int a = incoming_graph[i].size();
      int b = outgoing_graph[i].size();
      double wp = (double)a / (a + b);
      result.push_back(WinProb(i, wp));
    }

    sort(result.begin(), result.end());

    int prev_cnt = count_violations(result);

    freopen("/Volumes/Programming/test/WP/alpha1.dat", "w", stdout);
    cout << prev_cnt << '\n';
    fclose(stdout);
}