#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > incoming_graph, outgoing_graph;
vector<int> diff_degree;
int n;

void makeGraph()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("/Volumes/Programming/research/PM/input.txt", "r", stdin);

    // p 만들기 위한 초기 작업
    default_random_engine generator;
    uniform_real_distribution<double> dist(0.0, 1.0);

    int m;
    int u, v;
    double p, alpha = 0.0;
    cin >> n >> m;

    incoming_graph.clear();
    outgoing_graph.clear();
    diff_degree.clear();

    incoming_graph.resize(n + 1);
    outgoing_graph.resize(n + 1);
    diff_degree.resize(n+1);

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
}

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

    return result;
}

class WinProb
{
public:
    int v;
    double prob;
    WinProb(int v, double prob)
    {
        this->v = v;
        this->prob = prob;
    }
    friend bool operator<(const WinProb &wp1, const WinProb &wp2)
    {
        return wp1.prob < wp2.prob;
    }
};

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
    
    return vResult;
}

int main()
{
    makeGraph();
    // vector<int> result = greedyOrder();
    vector<int> result = winProb();
    cout << result.size() << '\n';
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';

    return 0;
}