#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > incoming_graph, outgoing_graph;

int count_violations(vector<int> &result)
{
    int cnt = 0;
    for (int i = 0; i < result.size(); i++)
    {
        int node = result[i];
        for (int j = i + 1; j < result.size(); j++)
        {
            for (int k = 0; k < incoming_graph[node].size(); k++)
            {
                if (result[j] == incoming_graph[node][k])
                    cnt++;
            }
        }
    }
    return cnt;
}

int left_cnt(vector<int> &result, int start, int end) {
    int cnt = 0;
    int node = result[start];
    for(int i=start+1; i<=end; i++) {
        for(int j=0; j<outgoing_graph[node].size(); j++) {
            if(result[i] == outgoing_graph[node][j]) cnt--;
        }
        for(int j=0; j<incoming_graph[node].size(); j++) {
            if(result[i] == incoming_graph[node][j]) cnt++;
        }
    }
    return cnt;
}

int right_cnt(vector<int> &result, int start, int end) {
    int cnt = 0;
    int node = result[end];
    for(int i=start; i<end; i++) {
        for(int j=0; j<outgoing_graph[node].size(); j++) {
            if(result[i] == outgoing_graph[node][j]) cnt++;
        }
        for(int j=0; j<incoming_graph[node].size(); j++) {
            if(result[i] == incoming_graph[node][j]) cnt--;
        }
    }
    return cnt;
}

void print(vector<int> &arr) {
  for(int i=0; i<arr.size(); i++) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
}

void rotate(vector<int> &arr, int start, int end)
{
    int temp = arr[end], p;
    for (p = end; p > start; p--)
    {
        arr[p] = arr[p - 1];
    }
    arr[p] = temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("/Volumes/Programming/PositionMove/input.txt", "r", stdin);
    int n, m;
    int u, v;
    cin >> n >> m;
    
    incoming_graph.resize(n + 1);
    outgoing_graph.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        outgoing_graph[u].push_back(v);
        incoming_graph[v].push_back(u);
    }

    vector<int> result;
    result.push_back(1);
    result.push_back(2);
    result.push_back(3);
    result.push_back(4);
    result.push_back(5);
    result.push_back(6);
    result.push_back(7);

    int prev_cnt = count_violations(result);
    int cur_cnt = INT32_MAX;

    cout << prev_cnt << '\n';
    print(result);

    bool updated = true;
    int min = 1;

    while (updated)
    {
        updated = false;
        for (int i = 0; i < n; i++)
        {
            vector<int> copy_result(result);
            min = 1;
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
                  // if(min >= cur_cnt) {
                  //   min = cur_cnt;
                  //   copy(copy_result.begin(), copy_result.end(), result.begin());
                  // }
                  copy(copy_result.begin(), copy_result.end(), result.begin());
                }
            }
        }
    }

    print(result);
    cout << count_violations(result) << '\n';


    return 0;
}