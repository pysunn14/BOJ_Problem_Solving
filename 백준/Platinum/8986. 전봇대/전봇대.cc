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

ll x[101010];
int N; 

ll f(ll d)
{
    ll sum = 0;
    ll now = 0;

    FOR(i,N,1)
    {
        now += d;
        sum += llabs(x[i] - now);
    }
    return sum;
}

int main()
{
    fio();

    cin>>N;
    FOR(i,N,0) cin>>x[i];

    if(N < 3) 
    {
        cout << 0;
        return 0;
    }

    //solve
    int lo = 0, hi = x[N-1];

    while (hi - lo >= 3)
    {
        int p = (lo*2 + hi)/3;
        int q = (lo + hi*2)/3;
        if (f(p) >= f(q)) lo = p;
        else hi = q;
    }

    ll m = INT64_MAX;
    FOR(i,hi+5,lo) m = min(m, f(i));

    cout << m;
}