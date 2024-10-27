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

const int sz = 101010;
ll A[sz];
ll tree[sz * 4];

ll f(ll a, ll b)
{
    return a + b;
}

ll init(int lo, int hi, int node)
{
    if (lo == hi) return tree[node] = A[lo];
    return tree[node] = f(init(lo, mid, node * 2), init(mid + 1, hi, node * 2 + 1));
}

ll query(int lo, int hi, int node, int left, int right)
{
    if (left > hi || right < lo) return 0;
    if (left <= lo && hi <= right) return tree[node];
    return f(query(lo, mid, node * 2, left, right), query(mid + 1, hi, node * 2 + 1, left, right));
}

void update(int lo, int hi, int node, int idx, ll value)
{
    if (idx < lo || idx > hi) return;
    if (lo == hi)
    {
        tree[node] = value;
        return;
    }
    update(lo, mid, node * 2, idx, value);
    update(mid + 1, hi, node * 2 + 1, idx, value);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
}

int main()
{
    fio();

    int N; cin >> N;

    queue<pii> update_list;
    vector<pair<pii, pii>> query_list;

    FOR(i,N+1,1) cin >> A[i];

    init(1,N,1);

    int M; cin >> M;

    int n = 0;

    FOR(i,M,0)
    {
        int a;

        cin >> a;

        if(a == 1)
        {
            int i,v; cin >> i >> v;
            update_list.push({i,v});
        }

        else if(a == 2)
        {
            int k,i,v;
            cin >> k >> i >> v;
            query_list.push_back({{k,n},{i,v}});
            n++;
        }
    }


    sort(all(query_list));

    int K = 0;

    vector<pair<int,ll>> ans;
    FORE(q, query_list)
    {
        int k = q.first.first;
        int n = q.first.second;
        int i = q.second.first;
        int v = q.second.second;

        while (k > K && !update_list.empty())
        {
            int i = update_list.front().first;
            int v = update_list.front().second;
            update_list.pop();   

            update(1,N,1,i,v);
            K++;
        }
        ans.push_back({n,query(1,N,1,i,v)});
    }

    sort(all(ans));

    FORE(an,ans) cout << an.second << '\n';
}