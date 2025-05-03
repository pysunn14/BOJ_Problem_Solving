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

    test(q)
    {
        int n;
        int m;
        cin >> n >> m;
        
        int lo = m;
        int hi = m;
        int now = 0;
        
        bool ok = true;
        FOR(i, n, 0)
        {
            int t, l, h;
            cin >> t >> l >> h;
            
            // 현재에서 t초가 되었을 때 갈수있는 구간을 구함 
            lo -= (t - now);
            hi += (t - now);
            
            // 교차가 되는지를 판정 
            if(l > hi || h < lo)
            {
                ok = false;
            }
            
            lo = max(l, lo);
            hi = min(h, hi);

            now = t;
        }
        
        if(!ok) cout << "NO\n";
        else cout << "YES\n";
    }
}