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

vector<int> graph[20202];
bool ok;
int color[20202];
bool vis[20202];

int main()
{
    fio();

    test(K)
    {
        ok = true;

        FOR(i,20202,0)
        {
            graph[i].clear();
            color[i] = 0;
            vis[i] = false;
        }
        
        int V,E; cin >> V >> E;

        FOR(i,E,0)
        {
            int u, v; 
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        FOR(i,V+1,1) 
        if(color[i] == 0) 
        {
            queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty())
            {
                int now = q.front();
                q.pop();

                FORE(next, graph[now])
                {
                    if(color[next]) continue;
                    if(1 == color[now]) color[next] = 2;
                    else color[next] = 1;
                    q.push(next);
                }
            }
        }

        FOR(i,V+1,1) 
        {
            FORE(next, graph[i])
            {
                if(color[i] == color[next])
                ok = false;
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}