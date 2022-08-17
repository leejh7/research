#include <vector>
using namespace std;

extern vector<vector<int> > incoming_graph, outgoing_graph;

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