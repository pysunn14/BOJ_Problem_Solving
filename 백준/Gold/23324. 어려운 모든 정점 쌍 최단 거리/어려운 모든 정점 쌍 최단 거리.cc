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

vector<int> graph[101010];
bool vis[101010];

ll L_COUNT, R_COUNT;
int L,R;

void L_dfs(int now)
{
    L_COUNT++;
    vis[now] = true;
    if(now == R) 
    {
        cout << 0;
        exit(0);
    }
    FORE(next, graph[now]) if(!vis[next]) L_dfs(next);
}

void R_dfs(int now)
{
    R_COUNT++;
    vis[now] = true;
    FORE(next, graph[now]) if(!vis[next]) R_dfs(next);
}

int main()
{
    fio();
    int N, M, K; cin>>N>>M>>K;

    FOR(i, M + 1, 1)
    {
        int u,v; cin>>u>>v;
        //가중치가 1인 간선
        if(i == K)
        {
            L = u;
            R = v;
            continue;
        }
        
        graph[u].push_back(v);
        graph[v].push_back(u);

    }

    L_dfs(L);
    R_dfs(R);

    cout<<L_COUNT * R_COUNT<<'\n';

}