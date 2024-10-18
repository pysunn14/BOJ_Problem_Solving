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

void update(int lo, int hi, int node, int idx, int value)
{
    if(idx < lo || idx > hi) return;
    if(lo == hi)
    {
        tree[node] += value;
        return;
    }
    update(lo,mid,node*2,idx,value);
    update(mid+1,hi,node*2+1,idx,value);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int lo, int hi, int node, int left, int right)
{
    if(right < lo || left > hi) return 0;
    if(left <= lo && hi <= right) return tree[node];
    return query(lo,mid,node*2,left,right) + query(mid+1,hi,node*2+1,left,right);
}

int main()
{
    fio();

    int n; cin >> n;
    ll inversion = 0;

    vector<pii> v;
    FOR(i,n+1,0) v.push_back({0,0});
    FOR(i,n+1,1) cin >> v[i].first;
    FOR(i,n+1,1) cin >> v[i].second;

    sort(all(v));
    reverse(all(v));

    FORE(e, v)
    {
        int now = e.second;
        inversion += query(1,n,1,1,now-1);
        update(1,n,1,now,1);
    }
    if(inversion % 2 == 0) cout << "Possible";
    else cout << "Impossible";
}