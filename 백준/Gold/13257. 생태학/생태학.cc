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

long double dp[6][21];

long double c[21][21];

int main()
{
    fio();
    
    for(int i = 1 ; i <= 20 ; i++)
    {
        c[i][0] = 1; 
        c[i][i] = 1; 

        for(int j = 1 ; j < i ; j++) 
        {
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }

    c[0][0] = 1;
    
    int N,C,D,M; cin >> N >> C >> D >> M; 

    for(int j = 0 ; j <= N; j++) dp[1][j] = (C == j); // 1일차일때 j마리를 태그할 확률은?? C=j 이면 1이고, C!=j 이면 0임. 

    for(int i = 2 ; i <= D ; i++)
    {
        for(int j = 1 ; j <= N; j++) 
        {
            for(int k = 0 ; k <= C; k++) 
            {
                if(j - k < 0) continue;  
                dp[i][j] += dp[i-1][j-k] * (c[j-k][C-k] * c[N-j+k][k] / c[N][C]); 
            }
        }
    }
       
    cout << fixed;
    cout.precision(10);
    cout << dp[D][M]; 
}