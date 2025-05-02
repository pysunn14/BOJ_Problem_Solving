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

    test(T)
    {
        int n; cin >> n;
        
        ll a[101010];
        FOR(i,n,0) cin >> a[i];

        bool ok = false;
        for(int i = 0 ; i < n - 1; i++)
        {
            if(a[i] > a[i+1]) 
            {
                ok = true;
                break;
            }
        }

        if(!ok) 
        {
            cout << 0 << '\n';
            continue;
        }
        
        ll mn = INT_MAX;
        ll mx_diff = 0;

        for(int i = n - 1 ; i >= 0 ; i--)
        {
            mn = min(mn, a[i]);
            mx_diff = max(a[i] - mn, mx_diff);
        }

        cout << (ll)log2(mx_diff) + 1 << '\n'; 
    }
}