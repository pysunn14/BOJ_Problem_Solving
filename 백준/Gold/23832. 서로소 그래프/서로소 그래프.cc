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

vector<int> ret;

bool prime[50505];
void sieve(int n)
{
    FOR(i,n+1,1) prime[i] = true;
    prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    if (prime[i]) for (int j = i * i; j <= n; j += i) prime[j] = false;

    FOR(i,n+1,1) if(prime[i]) ret.push_back(i);
}

ll euler_phi(int n)
{
    ll a = n;
    //모든 소인수
    FORE(p, ret) 
    {
        if(p > n) break;
        if(n % p == 0) a *= (1.0 - 1.0 / p);
    }
    return a;
}

int main()
{
    fio();
    int N; 
    cin >> N;
    sieve(N);
    
    ll ans = 0;
    FOR(i,N+1,2) ans += euler_phi(i);
    cout << ans;
}