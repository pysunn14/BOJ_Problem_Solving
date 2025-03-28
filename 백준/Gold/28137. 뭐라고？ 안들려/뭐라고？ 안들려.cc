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

    int n, k; cin >> n >> k;

    map<ll,ll> m;

    FOR(i,n,0)
    {
        ll x, y; cin >> x >> y;
        m[k * x - y]++;
    }

    // 같은거 개수 다 구해주면 끝 

    ll ans = 0;
    for(auto[v,c] : m)
    {
        ans += c * (c - 1);
    }
    cout << ans;
}