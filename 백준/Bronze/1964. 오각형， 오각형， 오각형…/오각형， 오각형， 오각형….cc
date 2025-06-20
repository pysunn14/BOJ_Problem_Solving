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

const ll mod = 45678;

ll d[10101010];

int main()
{
    fio();

    int n; cin >> n;

    d[1] = 5;

    for(int i = 2 ; i <= n; i++)
    {
        d[i] = d[i-1] + 3 * i + 1;

        d[i] %= mod;
    }

    cout << d[n];
}