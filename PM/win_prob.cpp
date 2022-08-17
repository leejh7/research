#include "win_prob.h"
#include "count_violations.h"
#include <iostream>
#include <algorithm>
using namespace std;

extern vector<vector<int> > incoming_graph, outgoing_graph;
extern int n;

vector<int> winProb() {
    vector<WinProb> result;
    vector<int> vResult;

    for (int i = 1; i <= n; i++)
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