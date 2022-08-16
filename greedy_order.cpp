#include "greedy_order.h"
#include "count_violations.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

extern vector<vector<int> > incoming_graph, outgoing_graph;
extern vector<int> diff_degree;
// extern int count_violations(vector<int> &result);

void removeEdge(int v, vector<vector<int> > graph, bool isIncome)
{
    for (int i = 0; i < graph[v].size(); i++)
    {
        int next = graph[v][i];
        if (diff_degree[next] != INT32_MIN)
        {
            if (isIncome)
                diff_degree[next]++;
            else
                diff_degree[next]--;
        }
    }
}

void createResult(stack<int> &res_stack, vector<int> &result)
{
    int idx = 0;
    while (!res_stack.empty())
    {
        result[idx++] = res_stack.top();
        res_stack.pop();
    }
}

vector<int> greedyOrder()
{
    queue<int> q;
    stack<int> res_stack;
    vector<int> result;

    int n = diff_degree.size() - 1;
    result.resize(n);

    while (res_stack.size() < n)
    {
        // find index max degree
        int max_degree = *max_element(diff_degree.begin() + 1, diff_degree.end());
        for (int i = 1; i <= n; i++)
        {
            if (diff_degree[i] == max_degree)
            {
                q.push(i);
                res_stack.push(i);
                diff_degree[i] = INT32_MIN;
            }
        }

        while (!q.empty())
        {
            // remove v from the graph
            int v = q.front();
            q.pop();

            removeEdge(v, incoming_graph, true);
            removeEdge(v, outgoing_graph, false);
        }
    }

    createResult(res_stack, result);

    int cnt = count_violations(result);

    FILE* fp = freopen("/Volumes/Programming/PositionMove/DATA/orialpha1.dat", "w", stdout);
    cout << "GO " << cnt << '\n';

    return result;
}