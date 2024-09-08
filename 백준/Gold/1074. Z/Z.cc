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

ll N, R, C;
ll Z(ll n, ll r, ll c)
{
    if(n < 1) return 0;

    ll pos;
    if(r < (1<<(n-1)))
    {
        if(c < (1<<(n-1))) pos = 0;
        else pos = 1;
    }

    else
    {
        if(c < (1<<(n-1))) pos = 2;
        else pos = 3;
    }
    return pos * (1<<(2*n-2)) + Z(n-1, r % (1<<(n-1)), c % (1<<(n-1)));
}

int main()
{
    fio();
    cin>>N>>R>>C;
    cout<<Z(N,R,C);
}