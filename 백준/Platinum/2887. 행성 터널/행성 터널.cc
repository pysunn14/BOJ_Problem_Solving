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

typedef struct {

    int n;
    int x;
    int y;
    int z;

}node;

ll ans;
int N;

// 모든 간선을 후보 간선으로 정할 필요가 없음
// 정렬 기준 인접 간선만 정하면 상관 없음

int parent[101010];

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
        if(a < b) parent[b] = a;
        else parent[a] = b;
    }
}

vector<pair<ll, pii>> edge; // distance, {node, node}

void mst()
{
    FOR(i,101010,0) parent[i] = i;

    sort(all(edge),[](pair<ll, pii> a, pair<ll, pii> b)
        { return a.first < b.first; });

    // N-1 개까지 

    int i = 0;
    int conn = 0;
    for(int i = 0 ; conn < N - 1 && i < edge.size() ; i++)
    {
        // 이미 연결한 간선이면 무시 

        ll dist = edge[i].first;
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        
        if(find(a) == find(b)) continue;

        // merge 
        merge(a,b);
        ans += dist;
    }
}

int main()
{
    fio();

    cin >> N;

    vector<node> v;

    FOR(i,N+1,1)
    {
        int x,y,z;

        cin >> x >> y >> z;

        v.push_back({i,x,y,z});
    }

    // x
    sort(all(v), [](node a, node b)
         { return a.x < b.x; });

    // add edge
    FOR(i,N-1,0)
    {
        ll dist = min({llabs(v[i + 1].x - v[i].x), llabs(v[i + 1].y - v[i].y), llabs(v[i + 1].z - v[i].z)});
        edge.push_back({dist, {v[i].n , v[i+1].n}});
    }

    // y
    sort(all(v), [](node a, node b)
         { return a.y < b.y; });

    // add edge
    FOR(i, N - 1, 0)
    {
        ll dist = min({llabs(v[i + 1].x - v[i].x), llabs(v[i + 1].y - v[i].y), llabs(v[i + 1].z - v[i].z)});
        edge.push_back({dist, {v[i].n , v[i+1].n}});
    }

    // z
    sort(all(v), [](node a, node b)
         { return a.z < b.z; });
         
    // add edge
    FOR(i, N - 1, 0)
    {
        ll dist = min({llabs(v[i + 1].x - v[i].x), llabs(v[i + 1].y - v[i].y), llabs(v[i + 1].z - v[i].z)});
        edge.push_back({dist, {v[i].n , v[i+1].n}});
    }

    // mst 
    mst();

    cout << ans;
}