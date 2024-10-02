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

const int sz = 1010101;
int tree[sz * 4];

int f(int a, int b)
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
    int n; cin >> n;
    
    ll cnt = 0;

    vector<pii> v;
    FOR(i,n+1,1) 
    {
        int x; cin>>x;
        v.push_back({x,i});
    }

    sort(all(v));
    reverse(all(v));

    FORE(e, v)
    {
        int value = e.second;

        cnt += query(1,n,1,1,value-1);
        update(1,n,1,value,1);
    }
    cout << cnt;
}