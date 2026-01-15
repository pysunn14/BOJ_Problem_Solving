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

ll r[501], c[501];
ll dp[501][501]; 
int N; 

int main()
{
    fio();

    cin >> N;

    for(int i = 1 ; i <= N ; i++) cin >> r[i] >> c[i];
    
    // dp[i][j] : i번행렬부터 j번행렬까지 곱해서 합쳤을 때 필요한 곱셈 연산의 수 

    // dp[i][j] 는 바로 그 사이애들에서 최소치로 올것이 맞다. i <= k < j 인 k 인데, dp[i][k] + dp[k+1][j] 

    // 두 행렬 a, a+1 이 있다고 할때 행렬을 곱하는 비용은 r[a] * c[a] * c[a+1] 이다. 

    // len1일때는요? 합치기 비용이 없어요. 

    for(int i = 1 ; i <= N ; i++) dp[i][i] = 0;

    // 파일 합치기처럼 풀면 풀림 
    for(int len = 2 ; len <= N ; len++)
    {
        for(int i = 1 ; i <= N ; i++) 
        {
            int j = i + len - 1;
         
            if(j > N) continue;

            dp[i][j] = 1e18; 

            for(int k = i ; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + r[i] * c[k] * c[j]); 
            }
        }
    }

    cout << dp[1][N]; 
}