#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define test(a) int _; cin >> _; FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

#define piii tuple<ll,ll,ll> 

vector<piii> graph[202020]; // dist, time, next // 현재 거리가 가장 짧은 간선부터 보면 된다. 
const ll INF = INT_MAX;
ll dis[202020];
int N, M; 
ll ans = -1; 

int di(ll x)
{
    int start = 1; 
    int end = N;

    // dis INF로 채우기     
    fill(dis+1, dis+N+1, INF);
    priority_queue<pii> pq; // 현재까지 소요된 time, next 만 채우면 되지 않을까? 
    pq.push({-x, start});
    
    bool iter = true;
    while (!pq.empty() && iter)
    {
        auto node = pq.top(); 
        
        // 현재 까지 지난 시각 
        ll k = -get<0>(node);
        ll now = get<1>(node);
        pq.pop();
        
        if(k > dis[now]) continue; 
        
        for(int i = 0 ; i < graph[now].size() ; i++)
        {
            auto next = graph[now][i];
            
            ll d = get<0>(next); // 얼음다리의 길이 
            ll t = get<1>(next); // 무너질 예정의 시간 
            ll nextnode = get<2>(next); // 다음 노드 
            
            // 갈 수 있는 상황면서, 더 나은 상황이 된다면 
            if(t >= k + d && dis[nextnode] > k + d)
            {
                // 가장 짧은 시간에 온 걸로 업데이트를 합니다. 
                dis[nextnode] = k + d;
                pq.push({-dis[nextnode], nextnode});
                if(nextnode == end)
                {
                    iter = false;
                    break;
                }
            }
        }
    }

    if(dis[end] == INF) return -1;
    ans = max(ans, x);
    return x;
}

int main()
{
    fio();
    
    cin >> N >> M;

    FOR(i,M+1,1)
    {
        int u,v,d,t; 
        cin >> u >> v >> d >> t;
        graph[u].push_back({d,t,v}); 
        graph[v].push_back({d,t,u}); 
    }
    
    ll lo = -1;
    ll hi = 1e9 + 1;
    
    while (lo + 1 < hi)
    {
        if(di(mid) == -1) hi = mid;
        else lo = mid;
    }
    
    cout << ans;
}