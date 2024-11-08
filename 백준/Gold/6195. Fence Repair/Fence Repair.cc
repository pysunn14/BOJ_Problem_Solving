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

    priority_queue<ll> pq;

    FOR(i,N,0)
    {
        int x; cin >> x;
        pq.push(-x);
    }

    ll ans = 0;
    while(!pq.empty())
    {
        ll a = -pq.top(); pq.pop();
        if(pq.empty()) break;

        ll b = -pq.top();
        pq.pop();
        ans += a + b;
        pq.push(-(a+b));
    }

    cout << ans;
}