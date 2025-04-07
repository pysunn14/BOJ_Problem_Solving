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
ll dp[101];
ll comb[101][101];

int main()
{
    fio();

    // 교란 순열 DP 계산

    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3 ; i <= 100 ; i++)
    {
        dp[i] = (((i - 1) * dp[i - 2]) % mod + ((i - 1 ) * dp[i - 1]) % mod) % mod;
    }

    // 조합수 계산 

    for(int i = 1 ; i <= 100 ; i++)
    {
        comb[i][0] = 1;
        comb[i][i] = 1;

        for(int j = 1 ; j < i ; j++)
        {
            comb[i][j] = (comb[i - 1][j - 1] % mod + comb[i - 1][j] % mod) % mod;
        }
    }
    
    int N; cin >> N; 

    if(N % 4 == 0) cout << dp[N] << '\n';   

    else 
    {
        ll no = N % 4;
        cout << (comb[N][no] % mod * dp[N - no] % mod) % mod << '\n';
    }
}