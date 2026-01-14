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

int main()
{
    fio();

    test(T)
    {
        int K; cin >> K;
        ll A[501] = {0};
        FOR(i,K+1,1) cin >> A[i];

        ll sum[501] = {0};

        sum[1] = A[1];
        for(int i = 2 ; i <= K; i++) sum[i] = sum[i-1] + A[i];
        
        ll dp[501][501]; 

        for(int i = 1 ; i <= K ; i++) for(int j = 1 ; j <= K ; j++) dp[i][j] = 1e18;

        // 길이 0개 
        for(int i = 1 ; i <= K ; i++) dp[i][i] = 0; // 파일 하나만 생각하면 합침 비용이 없음.  
        
        // 길이가 len 짜리 인 것을 다 합침. 
        for(int len = 1 ; len <= K; len++)
        {
            for(int i = 1 ; i <= K ; i++)
            {
                int j = i + len - 1;

                if(j > K) break;
                
                for(int k = i ; k < j ; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
                }
            }
        }
        
        cout << dp[1][K] << '\n';
    }
}