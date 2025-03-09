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


const ll mod = 1e9 + 7;
const int sz = 4000000;
ll fact[sz + 1];
ll inv_fact[sz + 1];

// a의 b승 구하는 함수
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

ll binomial(int n, int r)
{
    return (((fact[n] % mod ) * (inv_fact[r] % mod))) % mod * (inv_fact[n-r] % mod) % mod;
}

void fastFactorial()
{
    fact[0] = fact[1] = 1;
    for(ll i = 2 ; i <= sz ; i++)
    {
        fact[i] = fact[i-1] * i;
        fact[i] %= mod;
    }

    inv_fact[0] = 1;
    inv_fact[sz] = fp(fact[sz], mod-2) % mod;

    for(ll i = sz ; i >= 1 ; i--)
    {
        inv_fact[i-1] = (inv_fact[i] * i) % mod;
        inv_fact[i-1] %= mod;
    }
}

int main()
{
    fio();

    fastFactorial();
    int N,R; cin >> N >> R;
    cout << binomial(N,R);
}