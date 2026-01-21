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

bool vis[10101];
int dist[10101]; 
vector<pii> graph[10101]; // next, weight 

int n; 

void dfs(int i)
{
    vis[i] = true; 

    FORE(next, graph[i])
    {
        int node = next.first;
        int weight = next.second; 

        if(!vis[node])
        {
            dist[node] = dist[i] + weight; 
            dfs(node);  
        }
    }
}

int main()
{
    fio();

    cin >> n;

    for(int i = 0 ; i < n-1 ; i++)
    {
        int a,b,w; 
        
        cin >> a >> b >> w;

        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }

    // 1에서 가장 먼 거리로 쭉 가셈 
    dfs(1); 

    // 거리 가장 먼놈 찾기 
    int node = -1; 
    int distance = 0;

    for(int i = 1 ; i <= n ; i++)
    {
        if(distance < dist[i])
        {
            node = i;
            distance = dist[i];
        }
    }

    for(int i = 1 ; i <= n ; i++) 
    {
        vis[i] = false;
        dist[i] = 0;
    }
    dfs(node); 

    node = -1; distance = 0; 
    for(int i = 1 ; i <= n ; i++)
    {
        if(distance < dist[i])
        {
            node = i;
            distance = dist[i];
        }
    }

    cout << distance;
}