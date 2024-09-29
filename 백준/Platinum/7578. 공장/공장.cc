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

const int sz = 505050;
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
    int N; cin>>N;

    int A[sz];

    map<int,int> m;
    FOR(i,N+1,1) cin>>A[i];

    //좌표 압축
    FOR(i,N+1,1) 
    {
        int B; cin>>B;
        m[B] = i;
    }

    vector<pii> number;

    FOR(i,N+1,1)
    {
        int idx = i;
        int value;
        value = m[A[idx]];

        number.push_back({idx,value});
    }

    sort(all(number));
    reverse(all(number));

    ll cnt = 0;
    FORE(n, number)
    {
        int value = n.second;
        cnt += query(1,N,1,1,value-1);
        update(1,N,1,value,1);
    }
    cout << cnt;
}