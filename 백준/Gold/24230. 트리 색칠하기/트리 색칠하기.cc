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

ll cnt;
int C[202020];
vector<int> graph[202020];
bool vis[202020];
void dfs(int n)
{
    if(n == 1 && C[n] != 0) cnt++;
    vis[n] = true;
    FORE(next, graph[n])
    {
        if(!vis[next])
        {
            if(C[n] != C[next]) cnt++;
            dfs(next);
        }
        
    }
}

int main()
{
    fio();
    int N; cin >> N;
    FOR(i,N+1,1) cin >> C[i];
    FOR(i,N-1,0)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    cout << cnt;
}