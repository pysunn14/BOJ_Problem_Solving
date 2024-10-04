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

bool A[3030][3030];
int D[3030][3030];

int main()
{
    fio();

    int N,M; cin >> N >> M;

    ll cnt = 0;

    FOR(i,N+1,1)
    {
        string s; cin >> s;
        FOR(j,M,0)
        {
            if(s[j] == 'B') A[i][j+1] = 1;
         
            else A[i][j+1] = 0;
        }
    }
    
    FOR(i,N+1,1)
    {
        FOR(j,M+1,1)
        {
            if(i == 1 || j == 1) 
            {
                D[i][j] = 1;
            }
            else if((A[i][j] != A[i-1][j]) && (A[i][j] != A[i][j-1]) && (A[i][j] == A[i-1][j-1])) D[i][j] = min({D[i-1][j], D[i][j-1], D[i-1][j-1]}) + 1;
            else D[i][j] = 1;
        }
    }

    FOR(i,N+1,1)
    {
        FOR(j,M+1,1)
        {
            cnt += D[i][j];
        }
    }

    cout << cnt;
}