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

int main()
{
    fio();
    int N; cin >> N;

    int A[301][301];
    FOR(i,N,0)
    {
        FOR(j,N,0)
        {
            cin >> A[i][j];
        }
    }
    
    int B[301][301];
    FOR(i,N,0)
    {
        FOR(j,N,0)
        {
            cin >> B[i][j];
        }
    }

    int cnt = 0;
    int C[301][301];

    FOR(i,N,0)
    {
        FOR(j,N,0)
        {
            // C[i][j] 
            bool ok = false;

            FOR(k,N,0)
            {
                ok |= (A[i][k] & B[k][j]);
            }

            if(ok) cnt++;
        }
    }

    cout << cnt;
}