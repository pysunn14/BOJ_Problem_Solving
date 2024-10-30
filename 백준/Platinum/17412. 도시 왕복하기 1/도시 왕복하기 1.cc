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

int S = 1, T = 2;
int level[401];
vector<int> graph[401];
int c[401][401];
int f[401][401];
int work[401];

bool bfs()
{
    fill(level, level+401, -1);
    queue<int> q;
    q.push(S);
    level[S] = 0;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

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


int dfs(int now, int flow)
{
    if(now == T) return flow;

    for(int &i = work[now] ; i < graph[now].size() ; i++) 
    {
        int next = graph[now][i];

        if(level[next] == level[now] + 1 && c[now][next] - f[now][next] > 0)
        {
            int df = dfs(next, min(flow, c[now][next] - f[now][next])); //

            if(df)
            {
                f[now][next] += df;
                f[next][now] -= df;
                return df;
            }
        }
    }
    return 0;
}

int main()
{
    fio();
    int N,P; 
    cin >> N >> P;

    FOR(i,P,0)
    {
        int s,e; 
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
        c[s][e] = 1;
    }

    // dinic
    int total = 0;
    int flow = 0;
    while (bfs())
    {
        fill(work, work+401, 0);
        while (true) 
        {
            flow = dfs(S,INT_MAX);
            if(!flow) break;
            total += flow;
        }
    }

    cout << total;
}