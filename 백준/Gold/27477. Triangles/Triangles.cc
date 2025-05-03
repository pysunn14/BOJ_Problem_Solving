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

int A[2020][2020];
int main()
{
    fio();

    test(t)
    {
        int n; 
        cin >> n;

        int D[10] = {0};
        
        FOR(i,n+1,1)
        {
            string s; cin >> s;
            FOR(j,n+1,1)
            {
                A[i][j] = s[j-1] - '0';
            }
        }

        FOR(d,10,0)
        {
            int left = n, right = 1, lo = n, hi = 1;

            int cnt = 0;  
            FOR(i,n+1,1)
            {
                FOR(j,n+1,1)
                {
                    if(A[i][j] == d) 
                    {
                        cnt++;                        
                        left = min(left, j);
                        right = max(right, j);
                        lo = min(lo, i);
                        hi = max(hi, i);
                    }
                }
            }

            if(cnt <= 1) D[d] = 0;
            
            else 
            {
                FOR(i,n+1,1)
                {
                    FOR(j,n+1,1)
                    {
                        if(A[i][j] != d ) continue;
                        // 얘를 만약에 한 점으로 쓴다고 치자. 그러면 수직으로 쓸 때랑 수평으로 쓸 때를 비교해야된다. 
            
                        // 수직으로 쓸 때 
                        D[d] = max(D[d], max(i - 1, n - i) * max(right - j, j - left)); 
                        
                        // 수평으로 쓸 때 
                        D[d] = max(D[d], max(j - 1, n - j) * max(hi - i, i - lo));
                    }
                }
            }
        }
        
        FOR(i,10,0) cout << D[i] << ' ';
        cout << '\n';
    }
}