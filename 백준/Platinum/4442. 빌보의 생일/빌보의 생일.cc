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

ll f(ll a, ll b) {
    return a + b;
}

ll init(int lo, int hi, int node) {
    if (lo == hi) return tree[node] = A[lo];
    return tree[node] = f(init(lo, mid, node * 2), init(mid + 1, hi, node * 2 + 1));
}

ll query(int lo, int hi, int node, int left, int right) {
    if (left > hi || right < lo) return 0;
    if (left <= lo && hi <= right) return tree[node];
    return f(query(lo, mid, node * 2, left, right), query(mid + 1, hi, node * 2 + 1, left, right));
}

void update(int lo, int hi, int node, int idx, ll value) {
    if (idx < lo || idx > hi) return;
    if (lo == hi) {
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

    while(true)
    {
        //init 
        
        int N; cin >> N; if(!N) break;
        fill(A,A + N + 1,0);
        fill(tree,tree + 4 * N + 1, 0);

        map<string,int> m;

        FOR(i,N+1,1) 
        {
            string x; cin >> x;
            m[x] = i;
        }

        int a[101010];
        FOR(i,N+1,1) 
        {
            string y; cin >> y;
            a[i] = m[y];
        }

        // 문자열을 압축해서 숫자로 저장하기 
        ll inversion = 0;
        
        // 저장 
        vector<pii> v;
        FOR(i, N + 1, 0) v.push_back({0, 0});
        FOR(i, N + 1, 1) 
        {
            v.push_back({a[i],i});
        }

        sort(all(v));
        reverse(all(v));

        FORE(e, v)
        {
            int now = e.second;
            inversion += query(1, N, 1, 1, now - 1);
            update(1, N, 1, now, 1);
        }
        
        cout << inversion << '\n';
    }
}