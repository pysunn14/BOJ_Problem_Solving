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

int dp[4001][4001];
int main()
{
    fio();
    string S,T;
    cin >> S >> T;

    int s = S.size();
    int t = T.size();

    dp[0][0] = (S[0] == T[0]);
    FOR(j,t,1) if(S[0] == T[j]) dp[0][j] = 1;
    FOR(i,s,1) if(S[i] == T[0]) dp[i][0] = 1;

    FOR(i,s,1)
    {
        FOR(j,t,1)
        {
            if(S[i] == T[j]) 
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }

    int mx = 0;

    FOR(i,s,0) 
    {
        FOR(j,t,0) 
        {
            if(dp[i][j] > mx) {mx = dp[i][j];}
        }
    }
    cout << mx; 
}