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

    ll n,m,q; cin >> n >> m >> q;

    ll lenm = m / __gcd(n,m);
    ll lenn = n / __gcd(n,m);
    
    while (q--)
    {
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        
        ll ss = (sx == 1) ? lenn : lenm;
        ll ee = (ex == 1) ? lenn : lenm;

        if ((sy + ss - 1) / ss == (ey + ee - 1) / ee) cout << "YES\n";
        else cout << "NO\n";
    }
}