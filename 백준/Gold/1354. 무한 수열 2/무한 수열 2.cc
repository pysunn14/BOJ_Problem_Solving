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

map<ll,ll> dp;
ll N,P,Q,X,Y;

ll go(ll i)
{
    if(i <= 0) return 1;
    if(dp[i] > 0) return dp[i];
    return dp[i] = go(i/P-X)+go(i/Q-Y);
}

int main()
{
    fio();
    cin >> N >> P >> Q >> X >> Y;

    cout << go(N);
}