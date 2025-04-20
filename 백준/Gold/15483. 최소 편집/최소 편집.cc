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

    string a,b; cin >> a >> b;

    int I = a.size();
    int J = b.size();
    
    // init 
    FOR(j,J+1,0) dp[0][j] = j;
    FOR(i,I+1,0) dp[i][0] = i;

    FOR(i,I+1,1)
    {
        FOR(j,J+1,1)
        {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else if(a[i-1] != b[j-1])
            {        
                dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
            }
        }
    }
    
    cout << dp[I][J];
}