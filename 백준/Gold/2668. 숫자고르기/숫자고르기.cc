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

vector<int> graph[101];
bool vis[101];
bool fin[101];
bool cyc[101];

void dfs(int n)
{
    vis[n] = true;

    FORE(next, graph[n])
    {
        //cycle 확정이라면
        if(vis[next] && !fin[next])
        {
            cyc[next] = true;
        }

        // 아직 안감
        else if(!vis[next])
        {
            dfs(next);
        }
    }
    
    fin[n] = true;
}

int main()
{
    fio();
    int N; cin >> N;
    for(int i = 1 ; i <= N; i++)
    {
        int x; cin >> x;
        graph[i].push_back(x);
    }

    for(int i = 1 ; i <= N; i++)
    {
        fill(vis,vis+101,0);
        fill(fin,fin+101,0);
        dfs(i);
    }

    // 모든 cycle 요소 출력
    cout << accumulate(cyc, cyc+101, 0) << '\n';
    
    for(int i = 1 ; i <= N; i++)
    {
        if(cyc[i]) cout << i << '\n';
    }
}