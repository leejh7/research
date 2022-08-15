#include "make_graph.h"
#include <random>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > incoming_graph, outgoing_graph;
vector<int> diff_degree;

void makeGraph()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("/Volumes/Programming/resarch/input.txt", "r", stdin);

    // p 만들기 위한 초기 작업
    default_random_engine generator;
    uniform_real_distribution<double> dist(0.0, 1.0);

    int n, m;
    int u, v;
    double p, alpha = 1.0;
    cin >> n >> m;

    incoming_graph.resize(n + 1);
    outgoing_graph.resize(n + 1);
    diff_degree.resize(n+1);
    // rank.resize(n);

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        p = dist(generator);
        if (p < (alpha * u / (u + v)))
        {
            diff_degree[v]--;
            diff_degree[u]++;
            outgoing_graph[v].push_back(u);
            incoming_graph[u].push_back(v);
        }
        else
        {
            diff_degree[u]--;
            diff_degree[v]++;
            outgoing_graph[u].push_back(v);
            incoming_graph[v].push_back(u);
        }
    }

    cout << "완료!!!" << '\n';
}