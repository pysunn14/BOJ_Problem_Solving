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

// M이 너무 크므로 배열로 사용할 수 없음. 일단 C 
int dp[101][10101];
int m[101], c[101];

int main()
{
    fio();

    int N,M; 
    
    cin >> N >> M; // M : 확보할 메모리

    FOR(i,N+1,1) cin >> m[i]; 

    FOR(i,N+1,1) cin >> c[i]; 

    // j의 비용으로 확보가능한 최대 메모리를 계산하기
    FOR(i,N+1,1)
    {
        FOR(j, 10001, 0)
        {
            dp[i][j] = dp[i-1][j];
            if(j >= c[i]) dp[i][j] = max(dp[i][j], dp[i-1][j - c[i]] + m[i]);
        }
    }

    // M이상의 메모리가 확보된 상황 중에서 비용이 최소인 것을 출력
    int cost = INT_MAX;
    FOR(i,N+1,1)
    {
        FOR(j, 10001, 0)
        {
            if(dp[i][j] >= M)
            {
                cost = min(cost, j);
            }
        }
    }
    cout << cost;
}