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

int main()
{
    fio();
    
    while(true)
    {
        ll n,k; cin >> n >> k;
        
        map<int, vector<int>> tree;
        map<int, int> parent;
        map<int, int> depth;

        if(!n && !k) break;

        ll a[1010];
        FOR(i,n+1,1) cin >> a[i];
        
        queue<int> q;
        int node = a[1];

        vector<int> ret;

        // 인접한 것이 이전 +1 차이 일때마다 쭉 넣어주고 아닌경우 큐에서 빼서 그곳에다가 넣는다.
        FOR(i,n+1,2)
        {
            // 현재 인접하고 있다면 : 현재 큐 기준 부모에 삽입.
            if(i == 2 || a[i] == a[i-1] + 1)
            {
                tree[node].push_back(a[i]);   
                parent[a[i]] = node;
                depth[a[i]] = depth[node] + 1;
                q.push(a[i]);
            }

            // 부모를 변경
            else 
            {
                node = q.front();
                q.pop();

                tree[node].push_back(a[i]);   
                parent[a[i]] = node;
                depth[a[i]] = depth[node] + 1;
                q.push(a[i]);
            }
        }

        ll ans = 0;
        // 쭉 보면서 깊이가 같은 노드 중에 부모가 다른 노드를 개수에 모두 포함한다.
        FOR(i, n + 1, 1) 
        {
            if(a[i] != k && depth[a[i]] && depth[k] && parent[a[i]] != parent[k] && parent[parent[a[i]]] == parent[parent[k]]) ans++;
        }

        // k의 사촌 수는 ???
        cout << ans << '\n';
    }
}