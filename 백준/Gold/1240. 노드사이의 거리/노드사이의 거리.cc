#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<pii> graph[1010];
int dist[1010];

int bfs(int S, int E)
{
    queue<int> q;
    q.push(S);
    dist[S] = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        if(node == E) 
        {
            break;
        }
        
        for(auto next : graph[node])
        {
            if(dist[next.first] == -1) 
            {
                dist[next.first] = dist[node] + next.second;
                q.push(next.first);
            }
        }
    }

    return dist[E];
}

int main()
{
    int N, M; cin >> N >> M;

    for(int i = 0 ; i < N-1 ; i++)
    {
        int u,v,w; 
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    for(int i = 0 ; i < M ; i++)
    {
        int u,v; cin >> u >> v;

        for(int i = 1 ; i <= N ; i++) dist[i] = -1;

        cout << bfs(u, v) << '\n';
    }
}

