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

ll dp[1010][10101];
int w[1010], v[1010];

int main()
{
    fio();

    int N,K; 
    cin >> K >> N;
    FOR(i,N+1,1) cin >> v[i] >> w[i];

    FOR(i,N+1,1) 
    {
        FOR(j,K+1,1)
        {
            dp[i][j] = dp[i-1][j];
            if(w[i] <= j) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i] );
        }
    }
    cout << dp[N][K];
}