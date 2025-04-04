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

ll dp[21];

int main()
{
    fio();

    dp[1] = 0;
    dp[2] = 1;

    FOR(i,21,3) dp[i] = (i-1) * dp[i-2] + (i-1) * dp[i-1];
    
    test(T)
    {
        int N; cin >> N;
        cout << dp[N] << '\n';
    }
}