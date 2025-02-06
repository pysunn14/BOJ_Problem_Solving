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

    int N; cin >> N;

    vector<ll> add;
    vector<ll> sub;

    FOR(i,N,0)
    {
        int x,y; cin >> x >> y;
        add.push_back(x+y);
        sub.push_back(x-y);
    }

    sort(all(add));
    sort(all(sub));

    cout << max(add.back() - add[0], sub.back() - sub[0]);

}