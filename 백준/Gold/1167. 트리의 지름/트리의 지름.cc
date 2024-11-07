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

vector<pair<ll,ll>> graph[101010];
ll dist[101010];
ll mx;
int deepest;

void dfs(int n)
{
    FORE(node, graph[n])
    {
        int next = node.first;
        ll cost = node.second;

        if(dist[next] == -1) 
        {
            dist[next] = dist[n] + cost;
            dfs(next);
        }
    }

    if(dist[n] >= mx)
    {
        deepest = n;
        mx = dist[n];
    }
}

int main()
{
    fio();
    int V; cin >> V;

    FOR(i,V,0)
    {
        int a; 
        cin >> a;

        while (true)
        {
            int b, c;
            cin >> b;

            if(b == -1) break;
            cin >> c;
            graph[a].push_back({b,c});
        }        
    }

    // dfs 1
    fill(dist,dist+101010,-1);
    dist[1] = 0;
    dfs(1);

    // dfs 2
    mx = 0;
    fill(dist, dist+101010,-1);
    dist[deepest] = 0;
    dfs(deepest);
    cout << mx << '\n';
}