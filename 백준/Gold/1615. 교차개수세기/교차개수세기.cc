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

const int sz = 2020;
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

    int N,M; 
    cin>>N>>M;
    init(1,N,1);

    ll ivc = 0;
    vector<pii> V;

    FOR(i,M+1,1)
    {
        int a,b; cin>>a>>b;
        V.push_back({a,b});
    }

    // 첫번째 기준으로 일단 정렬한다. (높은순)
    sort(all(V));
    reverse(all(V));

    FOR(i,M+1,1)
    {
        int idx = V[i-1].second;
        //이전에 더 작은 값이 나왔던 개수
        ivc += query(1,N,1,1,idx-1);
        update(1,N,1,idx,1);
    }

    cout << ivc;
}