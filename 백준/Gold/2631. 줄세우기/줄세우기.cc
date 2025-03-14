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

int dp[201];

int main()
{
    fio();

    int N; cin >> N;

    int A[201];
    FOR(i,N+1,1) cin >> A[i];
    FOR(i,N+1,1) dp[i] = 1;
    
    FOR(i,N+1,1)
    {
        FOR(j,i,1)
        {
            if(A[i] > A[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    
    cout << N - *max_element(dp + 1, dp + N + 1);
}