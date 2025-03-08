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

int A[1010*1010];

vector<pii> graph[1010];

map<pii, bool> vis;

void dfs(int n)
{
    cout << n << ' ';

    FORE(next, graph[n])
    {
        int cnt = next.first;
        int node = next.second;

        if(vis[{n,node}] || vis[{node,n}]) continue;

        if(cnt == 2)
        {
            cout << node << ' ' << n << ' ';
            vis[{n,node}] = true;
        }

        else 
        {
            dfs(node);
        }
    }
}

int main()
{
    fio();

    int N; cin >> N;

    FOR(i,N+1,1)
    {
        FOR(j,N+1,1)
        {
            if(i == j || j == i + 1) continue; // j = i + 1이면 무시, j = i-1이면 1로. 나머지 
            if(j == i - 1) graph[i].push_back({1, j}); //cnt, node
            else graph[i].push_back({2, j}); //cnt, node
        }
    }

    cout << N * N + 1 << '\n';

    FOR(i,N,1)
    {
        cout << i << ' ' << i << ' ';
    }
    cout << N << ' ';

    // dfs  
    dfs(N);
}