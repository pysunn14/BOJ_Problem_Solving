#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define test(a) int _; cin >> _; FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define weight first
#define vertex second
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

const int sz = 505050;
ll A[sz];
ll tree[sz * 4];
ll lazy[sz * 4];

ll f(ll a, ll b)
{
   return a ^ b;
}

void lazy_update(int lo, int hi, int node)
{
    if(lazy[node])
    {
        tree[node] ^= lazy[node];
        if(lo!=hi)
        {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

ll init(int lo, int hi, int node)
{
   if (lo == hi) return tree[node] = A[lo];
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
   lazy_update(lo,hi,node);
   if (left > hi || right < lo) return;

   if(left <= lo && hi <= right)
   {
       tree[node] ^= value;
       if(lo != hi)
       {
           lazy[node*2] ^= value;
           lazy[node*2+1] ^= value;
       }
       return;
   }

   update(lo, mid, node * 2, left, right, value);
   update(mid + 1, hi, node * 2 + 1, left, right, value);
   tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
}

int main()
{
    fio();

    int N; cin>>N;

    FOR(i,N+1,1) cin>>A[i];

    int M; cin>>M;

    init(1,N,1);

    FOR(_,M,0)
    {
        int t; 
        cin>>t;

        if(t == 1)
        {
            int a,b,c; 
            cin>>a>>b>>c;
            update(1,N,1,a+1,b+1,c);
        }

        else
        {
            int a; cin>>a;
            cout<<query(1,N,1,a+1,a+1) << '\n';
        }

    }
}