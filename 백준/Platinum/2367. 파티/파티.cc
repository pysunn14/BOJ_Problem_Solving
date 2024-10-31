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

const int sz = 300;
int work[sz + 2];
int S = 0, T = sz + 1;

vector<int> graph[sz + 2];
int level[sz + 2];
int c[sz + 2][sz + 2];
int f[sz + 2][sz + 2];

bool bfs()
{
    fill(level, level + sz + 2, -1);
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
    for(int& i = work[now] ; i < graph[now].size() ; i++)
    {
        int next = graph[now][i];
        if(level[next] == level[now] + 1 && c[now][next] - f[now][next] > 0)
        {
            int df = dfs(next, min(flow, c[now][next] - f[now][next]));
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

int dinic()
{
    int total = 0;
    int cnt = 10;
    while (bfs())
    {
        fill(work, work + sz + 2, 0);
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

    int N,K,D; 
    cin >> N >> K >> D;

    // 소스 간선
    FOR(i,D+1,1)
    {
        int x; cin >> x;
        graph[S].push_back(i);
        graph[i].push_back(S);
        c[S][i] = x;
    }

    // 음식 간선
    FOR(i,N+1,1)
    {   
        int Z; 
        cin >> Z;

        FOR(j,Z,0)
        {
            int x; cin >> x;
            graph[x].push_back(i + 100);
            graph[i + 100].push_back(x);
            c[x][i + 100] = 1;
        }
    }

    // 사람 간선
    FOR(i, N + 1, 1)
    {
        graph[i + 100].push_back(T);
        graph[T].push_back(i + 100);
        c[i + 100][T] = K; 
    }

    cout << dinic();
}