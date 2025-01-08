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

const int sz = 50505;
ll A[sz];
ll tree[sz * 4][2];

ll min_init(int lo, int hi, int node)
{
    if (lo == hi) return tree[node][0] = A[lo];
    return tree[node][0] = min(min_init(lo, mid, node * 2), min_init(mid + 1, hi, node * 2 + 1));
}

ll max_init(int lo, int hi, int node)
{
    if (lo == hi) return tree[node][1] = A[lo];
    return tree[node][1] = max(max_init(lo, mid, node * 2), max_init(mid + 1, hi, node * 2 + 1));
}

ll min_query(int lo, int hi, int node, int left, int right)
{
    if (left > hi || right < lo) return INT_MAX;
    if (left <= lo && hi <= right) return tree[node][0];
    return min(min_query(lo, mid, node * 2, left, right), min_query(mid + 1, hi, node * 2 + 1, left, right));
}

ll max_query(int lo, int hi, int node, int left, int right)
{
    if (left > hi || right < lo) return 0;
    if (left <= lo && hi <= right) return tree[node][1];
    return max(max_query(lo, mid, node * 2, left, right), max_query(mid + 1, hi, node * 2 + 1, left, right));
}

void update(int lo, int hi, int node, int idx, ll value)
{
    if (idx < lo || idx > hi) return;
    if (lo == hi)
    {
        tree[node][0] = value;
        tree[node][1] = value;
        return;
    }

    update(lo, mid, node * 2, idx, value);
    update(mid + 1, hi, node * 2 + 1, idx, value);
    tree[node][0] = min(tree[node * 2][0], tree[node * 2 + 1][0]);
    tree[node][1] = max(tree[node * 2][1], tree[node * 2 + 1][1]);
}

int main()
{
    fio();

    int N,Q; cin >> N >> Q;
    FOR(i,N+1,1) cin >> A[i];

    min_init(1,N,1);
    max_init(1,N,1);

    while (Q--)
    {
        int a,b; cin >> a >> b;
        cout << abs(min_query(1,N,1,a,b) - max_query(1,N,1,a,b)) << '\n';
    }
    
}