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

ll d[21];

int main()
{
    fio();

    ll n; cin >> n;

    d[0] = 0;
    d[1] = 1;
    d[2] = 1;

    FOR(i,n+1,3) d[i] = d[i-1] + d[i-2];

    cout << d[n];
}