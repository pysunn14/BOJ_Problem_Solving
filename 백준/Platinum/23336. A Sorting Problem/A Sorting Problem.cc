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

const int sz = 202020;
ll A[sz];
ll tree[sz * 4];

ll f(ll a, ll b)
{
    return a + b;
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
        tree[node] += value;
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
    FOR(i,N+1,1) cin >> A[i];

    ll ans = 0;
    vector<pii> v;
    FOR(i,N+1,1)
    {
        v.push_back({A[i],i});
    }

    // 5 3 2 1 4
    sort(all(v));
    reverse(all(v));

    ll cnt = 0;
    FORE(e, v)
    {
        int idx = e.second;
        cnt += query(1,N,1,1,idx);
        update(1,N,1,idx,1);
    }

    cout << cnt;
}