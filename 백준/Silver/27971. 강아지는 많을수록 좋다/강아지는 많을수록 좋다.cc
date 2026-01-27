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

ll dp[101010];
bool range[101010]; 
ll inf = 100000; 
int N, M, A, B; 

ll go(int i)
{
    if(dp[i] != -1) return dp[i];
    if(range[i]) return dp[i] = inf;  
    
    int pathA = (i-A >= 0) ? min(inf, go(i-A) + 1) : inf;
    int pathB = (i-B >= 0) ? min(inf, go(i-B) + 1) : inf; 
    return dp[i] = min(pathA, pathB); 
}

int main()
{
    fio();

    for(int i = 0 ; i < 101010 ; i++) dp[i] = -1;
    dp[0] = 0; 
    
    cin >> N >> M >> A >> B; 

    for(int i = 1 ; i <= M; i++)
    {
        int L,R; 
        cin >> L >> R; 
        for(int i = L ; i <= R ; i++) range[i] = true; 
    }
    
    ll ans = go(N);

    if(ans >= 100000) cout << -1;
    else cout << ans;
}