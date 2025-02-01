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

int dp[1010][1010];
int main()
{
    fio();

    memset(dp, -1, sizeof(dp));
    dp[0][100] = 0;

    int N,K; 
    cin >> N >> K;

    int s[1010];
    int h[1010];
    
    FOR(i,N+1,1) cin >> s[i];
    FOR(i,N+1,1) cin >> h[i];

    // i번째 까지 생각
    FOR(i,N+1,0)
    {
        // 무게 제한 : 여기서는 체력
        FOR(prev_health, 101, 0)
        {
            if(dp[i][prev_health] == -1) continue; // 불가능한 체력상황

            // 체력 회복하기
            int health = min(prev_health + K, 100);
            
            // 1. 체력을 소모하지 않고 K회복된다.
            dp[i+1][health] = max(dp[i+1][health] , dp[i][prev_health]);

            // 2. 구간을 선택해서 DDR한다.            
            if(health - h[i] >= 0)
            {
                dp[i+1][health - h[i]] = max(dp[i+1][health-h[i]], dp[i][prev_health] + s[i]);
            }
        }
    }
    
    cout << *max_element(dp[N+1], dp[N+1] + 101);
}