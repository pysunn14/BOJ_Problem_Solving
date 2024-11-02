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

const int sz = 2005;
int S = 2001, A = 2002, T = 2003, B = 2004;
vector<int> graph[sz];
int work[sz];
int level[sz]; 
int c[sz][sz];
int f[sz][sz];

bool bfs()
{
    fill(level, level + sz, -1);
    queue<int> q;
    level[S] = 0;
    q.push(S);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        FORE(next, graph[now])
        {
            if(level[next] == -1 && c[now][next] - f[now][next] > 0)
            {
                q.push(next);
                level[next] = level[now] + 1;
            }
        }      
    }
    return level[T] != -1;
}

int dfs(int now, int flow)
{
    if(now == T) return flow;
    for(int &i = work[now] ; i < graph[now].size(); i++)
    {
        int next = graph[now][i];
        if(level[next] == level[now]+1 && c[now][next] - f[now][next] > 0)
        {
            int df = dfs(next, min(flow, c[now][next]-f[now][next]));
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
    int flow  = 0;
    while (bfs())
    {
        fill(work, work + sz, 0);
        while(flow = dfs(S,INT_MAX)) total += flow;
    }    
    return total;
}

int main()
{
    fio();
    int N,M,K;
    cin >> N >> M >> K;

    // 사람 작업
    FOR(i,N+1,1)
    {
        int h = i + 1000;
        int cnt; cin >> cnt;

        FOR(t,cnt,0)
        {
            int j; cin >> j;
            graph[j].push_back(h);
            graph[h].push_back(j);
            c[h][j] = 1;
        }
    }

    // 소스 -> A, B
    graph[S].push_back(A);
    graph[A].push_back(S);
    c[S][A] = N;

    graph[S].push_back(B);
    graph[B].push_back(S);
    c[S][B] = K;

    // A -> h
    FOR(i,N+1,1)
    {
        int h = i + 1000;
        graph[A].push_back(h);
        graph[h].push_back(A);
        c[A][h] = 1;
    }

    // K - > h
    FOR(i,N+1,1)
    {
        int h = i + 1000;
        graph[B].push_back(h);
        graph[h].push_back(B);
        c[B][h] = K;
    }
    
    // 작업 T
    FOR(j,M+1,1)
    {
        graph[j].push_back(T);
        graph[T].push_back(j);
        c[j][T] = 1;
    }

    cout << dinic();
}