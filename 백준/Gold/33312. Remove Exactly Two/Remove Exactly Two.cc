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

vector<int> graph[202020];
bool vis[202020];

void dfs(int n)
{
    vis[n] = true;
    FORE(next, graph[n]) if(!vis[next]) dfs(next);
}

int main()
{
    fio();
    
    test(t)
    {        
        int N; 
        cin >> N;
        vector<int> degree(N+1, 0);

        FOR(i,N+1,0)
        {
            graph[i].clear();
            vis[i] = false;
        }

        FOR(i,N-1,0)
        {   
            int u, v; 
            cin >> u >> v;
            
            graph[u].push_back(v);
            graph[v].push_back(u); 
            degree[u]++;
            degree[v]++;
        }

        FOR(iter, 2, 0)
        {
            vector<pii> v;

            FOR(i,N+1,1)
            {
                if(vis[i]) continue;
                v.push_back({degree[i], i});
            }
    
            sort(all(v));
            reverse(all(v));

            set<int> candidate;
            FORE(vv, v) if(vv.first == v[0].first) candidate.insert(vv.second);

            // degree가 가장 큰 노드들에 대해서만 생각 
            vector<pii> cand;
    
            FORE(node, candidate)
            {
                if(degree[node] < v[0].first) break;

                // 현재 간선과 연결된 degree동일 없으면 지우기 
                int cnt = 0;

                FORE(next, graph[node])
                {
                    if(next != node && candidate.find(next) != candidate.end()) cnt++;
                }
                cand.push_back({cnt, node});
            }

            // 개수가 가장 적은애를 지우면 된다. 
            sort(all(cand));

            int node = cand[0].second;

            // 간선 지우기
            FORE(next, graph[node]) degree[next]--; 
            degree[node] = 0;
            graph[node].clear();
            vis[node] = true;
        }
                
        // 연결요소 개수 확인 
        int ans = 0;
        FOR(i,N+1,1) if(!vis[i]) 
        {
            ans++;
            dfs(i);
        }

        cout << ans << '\n';
    }
}