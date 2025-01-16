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

int dp[501][501]; // dp[i][j] : i번째 회차까지 진행을 했는데, 마지막 무기를 j번째를 선택한 경우에 최소치
int t[501][501];  // t[n][m] : n회차 무기의 m번째 성능

int main()
{
    fio();

    int N,M;
    cin >> N >> M;
    
    FOR(i,N+1,1)
    {
        FOR(j,M+1,1)    
        {
            cin >> t[i][j];
        }
    }

    // base
    FOR(j,M+1,1) dp[1][j] = t[1][j];
    
    FOR(i,N+1,2)
    {
        FOR(j,M+1,1)
        {
            dp[i][j] = INT_MAX;
            
            FOR(k,M+1,1)
            {
                if(k == j) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][k]);
            }
            
            // j는 j를 골라서 만들어진 최소치가 된다.
            dp[i][j] += t[i][j];
        }
    }
    
    // ddd
    cout << *min_element(dp[N] + 1, dp[N] + M + 1);
}