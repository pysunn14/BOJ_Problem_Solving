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

    int a,b,c,d,e,f;

    cin >> a >> b >> c >> d >> e >> f;

    for(int x = -999 ; x <= 999 ; x++)
    {
        for(int y = -999 ; y <= 999 ; y++)
        {
            if(a * x + b * y == c && d * x + e * y == f)
            {
                cout << x << ' ' << y;
                return 0;
            }
        }
    }
    
}