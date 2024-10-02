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

ll N,P,Q;

set<ll> memo;
map<ll,ll> dp;

ll A(ll i)
{
    if(memo.find(i) != memo.end()) return dp[i];
    if(i == 0) return 1;
    dp[i] = A(i/P) + A(i/Q);
    memo.insert(i);
    return A(i/P) + A(i/Q); 
}

int main()
{
    fio();
    cin >> N >> P >> Q;
    dp[0] = 1;
    cout << A(N);
}