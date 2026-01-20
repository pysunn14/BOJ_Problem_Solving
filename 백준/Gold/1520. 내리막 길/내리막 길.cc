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

ll A[501][501];
ll dp[501][501];
int M, N; 

ll go(int i, int j)
{
    // already 
    if(dp[i][j] != -1) return dp[i][j];

    ll sum = 0;

    // go 
    if(i-1 >= 1 && A[i-1][j] > A[i][j]) sum += go(i-1, j); 
    if(j-1 >= 1 && A[i][j-1] > A[i][j]) sum += go(i, j-1); 
    if(j+1 <= N && A[i][j+1] > A[i][j]) sum += go(i, j+1); 
    if(i+1 <= M && A[i+1][j] > A[i][j]) sum += go(i+1, j); 
     
    return dp[i][j] = sum; 
}

int main()
{
    fio();

    cin >> M >> N;

    for(int i = 1 ; i <= M ; i++) for(int j = 1 ; j <= N ; j++) 
    {
        dp[i][j] = -1;
        cin >> A[i][j]; 
    }

    dp[1][1] = 1;

    // dp[i][j] := i,j까지 기준 내리막길만 써서 왔을 때 경로의 개수 
    cout << go(M,N); 
}