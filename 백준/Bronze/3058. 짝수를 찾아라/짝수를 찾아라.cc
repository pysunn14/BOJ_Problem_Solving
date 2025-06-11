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
        vector<int> v(7);

        FOR(i,7,0) cin >> v[i];

        ll sum = 0;
        int mn = INT_MAX;

        FORE(n, v)
        {
            if (n % 2 == 0)
            {
                sum += n;
                mn = min(mn, n);
            }
        }

        cout << sum << ' ' << mn << '\n';
    }
}