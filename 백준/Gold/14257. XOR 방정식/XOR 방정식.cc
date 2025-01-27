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

ll solve(ll S, ll X)
{
    // S < X 라면 불가능
    if(S < X) return 0;
    // S-X 가 홀수면 불가능 (제작 못함)
    if ((S - X) &  1) return 0;
    // (S-X >> 1)과 X 사이에서 겹치는 비트가 있으면 불가능
    if (X & (S - X >> 1)) return 0;

    // X에서 1인 비트의 개수
    ll K = __builtin_popcountll(X);
    ll res = 0;

    res = (1LL << K);
    if (S == X) res -= 2;
    return res;
}


int main()
{
    fio();

    ll S, X; cin >> S >> X;

    cout << solve(S,X);
}