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

ll d[88]; // 84까지 10^18 보다 작고 85부터 10^18보다 크다

string s2 = "*()";
string s3 = "*(()())";

char trace(ll n, ll k)
{
    if(d[n] < k || k < 1) return '0';
    if(k == 1) return '(';
    if(k == d[n]) return ')';
    
    if(n <= 2) return s2[k];
    if(n == 3) return s3[k];

    if(1 < k && k <= d[n-2] + 1) return trace(n-2, k-1);
    return trace(n-1, k - 1 - d[n-2]);
}

int main()
{
    fio();

    // dp
    d[1] = d[2] = 2;
    FOR(i,88,3) d[i] = 2 + d[i-2] + d[i-1];
    
    test(T)
    {
        ll n, k; 
        cin >> n >> k;

        if(n > 86)
        {
            ll nn;
            ll kk;

            if(n % 2 == 0)
            {
                nn = 86;
                kk = k - (n - 86LL)/2;
            }

            else 
            {
                nn = 85;
                kk = k - (n - 85LL)/2;
            }

            if(kk < 1) cout << '(' << '\n';
            else cout << trace(nn, kk) << '\n';
        }   
        
        else cout << trace(n, k) << '\n';
    }
}

