#include "win_prob.h"
#include "count_violations.h"
#include <iostream>
#include <algorithm>
using namespace std;

extern vector<vector<int> > incoming_graph, outgoing_graph;

// extern int count_violations(vector<int> &result);

vector<int> winProb() {
    vector<WinProb> result;
    vector<int> vResult;

    int n = incoming_graph.size() - 1;

    for (int i = 0; i < n; i++)
    {
        int a = incoming_graph[i].size();
        int b = outgoing_graph[i].size();
        double wp = (double)a / (a + b);
        result.push_back(WinProb(i, wp));
    }

    sort(result.begin(), result.end());
    for(int i=0; i<result.size(); i++) {
        vResult.push_back(result[i].v);   
    }

    int cnt = count_violations(vResult);
    
    cout << "WP " << cnt << '\n';
    
    return vResult;
}