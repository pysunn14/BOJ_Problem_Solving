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

    test(t)
    {
        int n,m; cin >> n >> m;

        set<int> a;

        FOR(i,n,0)
        {
            int x; cin >> x;
            a.insert(x);
        }
        int ans = 0;

        FOR(i,m,0)
        {
            int x; cin >> x;
            if(a.find(x) != a.end()) ans++;
        }
        
        cout << ans << '\n'; 
    }
}