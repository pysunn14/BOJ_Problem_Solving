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

int main()
{
    fio();

    int N, Q; 
    cin >> N >> Q;

    int A[3030];
    FOR(i, N+1, 1) cin >> A[i];

    int dp[3030]; // dp[i] : i번째가 LIS수열에 포함된다고 할때 LIS의 길이
    fill(dp, dp+3030,1);

    int rdp[3030];
    fill(rdp, rdp+3030,1);
    
    FOR(i, N+1, 2)
    {
        FOR(j, i, 1)
        {
            if(A[j] < A[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    reverse(A + 1, A + N + 1);
    FOR(i, N+1, 2)
    {
        FOR(j, i, 1)
        {
            if(A[j] > A[i]) rdp[i] = max(rdp[i], rdp[j] + 1);
        }
    }
    
    // 쿼리는 3천개 : DP를 미리 전처리해야지 
    while (Q--)
    {
        int x; cin >> x;
        // LIS DP를 돌리는데, A[i]는 반드시 포함시키면서 DP를 돌린다.     
        cout << dp[x] + rdp[N - x + 1] - 1<< '\n';
    }
}