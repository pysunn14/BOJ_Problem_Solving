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

    while(true)
    {
        ll n,k; cin >> n >> k;
        if(!n && !k) break;
        ll a[101]; 
        for(int i = 1 ; i <= n ; i++) cin >> a[i];

        // dp[i][j] : 길이가 i이면서 마지막 숫자가 j번째로 끝나는 수열의 개수 

        ll dp[101][101] = {0};
        
        dp[1][1] = 1;
        for(int j = 1 ; j <= n ; j++) dp[1][j] = 1; 

        for(int i = 2 ; i <= k ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                for(int h = 1 ; h < j; h++)
                {
                    // i 번째는 i-1번째 길이인데, a[h] < a[j] 보다 작은 애를 다 더해서 구한다. 
                    if(a[h] < a[j]) dp[i][j] += dp[i-1][h]; 
                }
            }
        }
                        
        // 길이가 K인 답 합산 
        ll ans = 0;
        for(int j = 1 ; j <= n ; j++) ans += dp[k][j];
        cout << ans << '\n';
    }

    return 0;
}