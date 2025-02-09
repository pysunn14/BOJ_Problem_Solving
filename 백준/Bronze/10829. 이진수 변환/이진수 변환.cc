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

    ll N; cin >> N;

    vector<bool> v;
    while (N > 0)
    {
        v.push_back(N % 2);
        N /= 2;
    }
    reverse(all(v));
    FORE(vv, v) cout << vv;
    
}