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

// print LCS

int dp[41][41];
int path[41][41];

int main()
{
    fio();

    FOR(i,41,0) FOR(j,41,0) path[i][j] = -1;

    string s,t; cin >> s >> t;

    int S = s.size();
    int T = t.size();

    dp[0][0] = (s[0] == t[0]);

    FOR(j,T,1) 
    {
        dp[0][j] = dp[0][j-1]  | (s[0] == t[j]);
        path[0][j] = 2;
        if(s[0] == t[j]) path[0][j] = 0;
    }
    FOR(i,S,1) 
    {
        dp[i][0] = dp[i-1][0] | (s[i] == t[0]);
        path[i][0] = 1;
        if(s[i] == t[0]) path[i][0] = 0;
    }

    FOR(i,S,1)
    {
        FOR(j,T,1)
        {
            // normal case
            if(dp[i-1][j] > dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j];
                path[i][j] = 1;
            }

            else
            {
                dp[i][j] = dp[i][j-1];
                path[i][j] = 2;
            }

            // equal character
            if(s[i] == t[j]) 
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                path[i][j] = 0;
            }
        }
    }

    // dp[S][T]부터 시작해서 역추적으로 출력
    vector<char> ans;

    int i = S-1, j = T-1;

    while (i >= 0 && j >= 0)
    {
        if(s[i] == t[j]) ans.push_back(s[i]);

        if(path[i][j] == 0)
        {
            i--;
            j--;
        }

        else if(path[i][j] == 1)
        {
            i--;
        }

        else if(path[i][j] = 2)
        {
            j--;
        }

    }
    
    reverse(all(ans));
    FORE(a, ans) cout << a;
}
