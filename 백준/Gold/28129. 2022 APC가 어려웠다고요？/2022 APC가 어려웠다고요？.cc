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

ll d[3030][3030];
ll mySolve()
{
    const ll mod = 1e9+7;
    pii ranges[3030];
    int n,k; 
    cin >> n >> k;
    FOR(i,n+1,1) cin >> ranges[i].first >> ranges[i].second;

    for (int j = ranges[1].first; j <= ranges[1].second; j++) d[1][j] = 1;

    for (int i = 2; i <= n; i++) {

        ll S[3001] = {0};
        FOR(j,3001,1) 
        {
            S[j] = S[j-1] + d[i-1][j];
        }

        for(int j = ranges[i].first ; j <= ranges[i].second ; j++)
        {
            int l = j-k, r = j+k;
            if(r > 3000) r = 3000;
            if(l < 1) l = 1;
            d[i][j] = S[r] - S[l-1];
            d[i][j] %= mod;
        }
    }

    ll ans = 0;
    for (int j = ranges[n].first; j <= ranges[n].second; j++) 
    {
        ans = ans + d[n][j];
        ans %= mod;
    }

    return ans;
}

int main()
{
    fio();

    cout << mySolve();
}