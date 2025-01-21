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

const int mod = 1e9;
int dp[1010101][20]; // dp[i][j] : i 숫자가 2^j까지 활용해서 만들수있는 경우의 수 

int main()
{
    fio();
    
    int N; 
    cin >> N;

    FOR(j,20,0) 
    {
        dp[0][j] = 1;
        dp[1][j] = 1;
    }
        
    FOR(i,N+1,1)
    {
        dp[i][0] = 1;
        
        FOR(j,20,1)
        {
            dp[i][j] = dp[i][j-1];
            dp[i][j] %= mod;

            if(i - (1 << j) < 0) continue;
            dp[i][j] += dp[i - (1 << j)][j];
            dp[i][j] %= mod;
        } 
    }

    cout << (dp[N][19] %= mod);
}