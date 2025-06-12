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

ll dp[70][10];

int main()
{
    fio();

    FOR(i,10,0) dp[1][i] = 1;

    FOR(i,66,2)
    {
        FOR(j,10,0)
        {
            FOR(k,10,j)
            {
                dp[i][j] += dp[i-1][k];
            }
        }
    }

    test(T)
    {
        int n; 
        cin >> n;
        cout << dp[n+1][0] << '\n';
    }
}