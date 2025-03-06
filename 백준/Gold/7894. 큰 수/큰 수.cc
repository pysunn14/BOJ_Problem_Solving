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

long double a;

int main()
{
    fio();

    test(t)
    {
        long double m; 
        cin >> m;
        a = 0;

        FOR(i,m+1,1)
        {
            a += log10l((long double)i);
        }

        cout << (int)a + 1 << '\n';
    }
    
}