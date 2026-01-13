#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std; 

#define pii pair<ll,ll>

vector<int> graph[101010]; 

int parent[101010];
int remain[101010];

int find(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if(a != b)
    {
        if(a < b) parent[a] = b;
        else parent[b] = a;
    }
}

int main()
{
    int N, M; cin >> N >> M; 

    for(int i = 1 ; i <= N ; i++) parent[i] = i; 

    // 간선을 사이클이 아니게끔 연결합니다. 그러면서 
    for(int i = 0 ; i < M ; i++) 
    {
        int u,v; cin >> u >> v; 

        graph[u].push_back(v);
        graph[v].push_back(u); 

        remain[u]++;
        remain[v]++;
    }

    for(int i = 1 ; i <= N ; i++) 
    {

        for(const auto& adj : graph[i])
        {
            if(find(i) != find(adj))
            {
                merge(i, adj);
                remain[adj]--;
                remain[i]--; 
            }
        } 
    }

    int sum = 0;

    for(int i = 1 ; i <= N ; i++) sum += remain[i];

    // 안쓴 간선이 두개 이상 남았다? 그럼 으악그래프 아님. 
    if(sum / 2 >= 2) cout << "No";
    else cout << "Yes"; 
    return 0;
}