#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

    int n; cin >> n;

    vector<double> a(n,0);

    FOR(i,n,0) cin >> a[i];

    if(a[0] + a[2] == 2 * a[1])
    {
        cout << a[n-1] + a[1] - a[0];
    }

    else
    {
        cout << (int)(a[n-1] * (a[1] / a[0]));
    }
}