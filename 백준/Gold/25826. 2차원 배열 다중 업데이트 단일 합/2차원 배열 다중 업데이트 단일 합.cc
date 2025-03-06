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

ll A[1010][1010];
ll imos[1010][1010];

int main()
{
    fio();

    int n, m; 
    cin >> n >> m;

    FOR(i,n,0)
    {
        FOR(j,n,0)
        {
            cin >> A[i][j];
        }
    }

    while (m--)
    {
        int c, i1, j1, i2, j2, k;

        cin >> c;

        if(c == 1)
        {
            cin >> i1 >> j1 >> i2 >> j2 >> k;

            imos[i1][j1] += k;
            imos[i1][j2+1] -= k;
            imos[i2 + 1][j1] -= k;
            imos[i2 + 1][j2 + 1] += k;
        }
        
        else 
        {
            cin >> i1 >> j1 >> i2 >> j2;

            // 가로 방향 누적합
            FOR(i,n,0)
            {
                FOR(j,n,1)
                {
                    imos[i][j] = imos[i][j-1] + imos[i][j];
                }
            }

            // 세로 방향 누적합
            FOR(j,n,0)
            {
                FOR(i,n,1)
                {
                    imos[i][j] = imos[i-1][j] + imos[i][j];
                }
            }
            
            // 마지막에만 저장되어 있다. 
            // 그렇다면 imos 를 진행하고 마지막에 누적합을 솩 하면 풀린다. 

            ll ans = 0;

            FOR(i,i2+1,i1)
            {
                FOR(j,j2+1,j1)
                {
                    ans += (A[i][j] + imos[i][j]);
                }
            }
            
            cout << ans;
        }
    }
}