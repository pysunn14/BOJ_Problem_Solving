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

const int sz = 501010;
int in[sz];
int out[sz];
vector<int> graph[sz];
ll A[sz];
ll tree[sz * 4];
ll lazy[sz * 4];

int cnt = 0;
void ETT(int n)
{
    
    in[n] = ++cnt;
    FORE(next ,graph[n]) if(!in[next]) ETT(next);
    out[n] = cnt;
}

void lazy_update(int lo, int hi, int node)
{
    if(lazy[node])
    {
        tree[node] += (hi - lo + 1) * lazy[node];

        //propagate
        if(lo != hi)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll f(ll a, ll b)
{
    return a + b;
}

ll init(int lo, int hi, int node)
{
    if (lo == hi)
        return tree[node] = A[lo];
    return tree[node] = f(init(lo, mid, node * 2), init(mid + 1, hi, node * 2 + 1));
}

ll query(int lo, int hi, int node, int left, int right)
{
    lazy_update(lo,hi,node);

    if (left > hi || right < lo) return 0;
    if (left <= lo && hi <= right) return tree[node];
    return f(query(lo, mid, node * 2, left, right), query(mid + 1, hi, node * 2 + 1, left, right));
}

void update(int lo, int hi, int node, int left, int right, ll value)
{
    lazy_update(lo, hi, node);

    if(right < lo || left > hi) return;

    if(left <= lo && hi <= right)
    {
        tree[node] += (hi - lo + 1) * value;
        
        //propagate
        if(lo != hi)
        {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }
    
    update(lo, mid, node * 2, left, right, value);
    update(mid + 1, hi, node * 2 + 1, left, right, value);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
}

int money[sz];
int main()
{
    fio();

    int n,m; cin >> n >> m;
    cin >> money[1];
    
    FOR(i,n+1,2) 
    {
        int p;
        cin >> money[i] >> p;
        graph[p].push_back(i);
    }

    ETT(1);

    FOR(i,n+1,1) A[in[i]] = money[i];
    init(1,n,1);

    while(m--)
    {
        char q; cin >> q;

        if(q == 'p')
        {
            int a, x; 
            cin >> a >> x;
            update(1, n, 1, in[a]+1, out[a], x);
        }
        else 
        {
            int a; cin >> a;
            cout << query(1, n, 1, in[a], in[a]) << '\n';
        }
    }
}