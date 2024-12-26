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

const ll mod = 1000003;

ll fp(ll a, ll b)
{
    if(b == 1) return a % mod;
    if(b % 2 == 0)
    {
        ll res = fp(a, b/2) % mod;
        return ( res % mod * res % mod ) % mod;
    }
    if(b % 2 == 1) return ((a % mod) * (fp(a, b - 1) % mod)) % mod;
}

int main()
{
    fio();

    ll K; cin >> K;
    ll ans = (fp(2,K)-1) % mod * (fp(2,K)-2 )%mod;
    ans %= mod;
    cout << (ans / 6);
}