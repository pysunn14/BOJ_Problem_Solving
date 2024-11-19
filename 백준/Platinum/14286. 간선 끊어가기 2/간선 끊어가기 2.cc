#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define test(a) int _; cin >> _; FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

const int MAX = 501;
vector<int> graph[MAX]; 

int S,T;
int n, m;
int c[MAX][MAX];
int f[MAX][MAX];
int level[MAX];
int work[MAX];

bool bfs()
{
    fill(level, level+MAX, -1);
    queue<int> q;
    q.push(S);
    level[S] = 0;

    while (!q.empty())
    {
        int now = q.front(); q.pop();
        FORE(next, graph[now])
        {
            if(level[next] == -1 && c[now][next] - f[now][next] > 0)
            {
                level[next] = level[now] + 1;
                q.push(next);
            }
        }
    }
    return level[T] != -1;
}

int dfs(int node, int max_flow)
{
    if(node == T) return max_flow;

    for(int &i = work[node] ; i < graph[node].size() ; i++)
    {
        int next = graph[node][i];

        if(level[next] == level[node] + 1 && c[node][next] - f[node][next] > 0)
        {
            int df = dfs(next , min(max_flow, c[node][next]-f[node][next]));
            if(df)
            {
                f[node][next] += df;
                f[next][node] -= df;         
                return df;
            }
        }
    }
    return 0;
}

int dinic()
{
    int total = 0;
    while (bfs())
    {
        fill(work, work + MAX, 0);
        int flow = 0;
        while (true) 
        {
            flow = dfs(S, INT_MAX);
            if(!flow) break;
            total += flow;
        }
    }
    return total;    
}

int main()
{
    fio();
    cin >> n >> m;

    FOR(i,m,0)
    {
        int a,b,w; 
        cin >> a >> b >> w;

        graph[a].push_back({b});
        graph[b].push_back({a});

        c[a][b] = w;
        c[b][a] = w;
    }

    cin >> S >> T;

    // max flow = min cut 
    cout << dinic();
}