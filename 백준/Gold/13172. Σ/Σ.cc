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

const ll mod = 1e9+7;

ll mul(ll a, ll b)
{
    if(b == 1) return a % mod;
    if(b % 2 == 0) 
    {
        ll ret = mul(a, b/2);
        return ((ret % mod) * (ret % mod)) % mod;
    }
    if(b % 2 == 1) return ((a % mod) * (mul(a, b-1) % mod) % mod);
}

int main()
{
    fio();
    int M; 
    cin >> M;

    ll sum = 0;

    FOR(i,M,0)
    {
        ll a,b; 
        cin >> a >> b;
        sum += (((b % mod) * (mul(a, mod-2) % mod)) % mod); 
        sum %= mod;
    }
    
    cout << sum;
}