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

    vector<ll> v;

    FOR(i,n,0)
    {
        int x; cin >> x;
        v.push_back(x);
    }

    sort(all(v));

    vector<ll> b;

    FOR(i,n,1)
    {
        b.push_back(stoi(to_string(v[0]) + to_string(v[i])));
        b.push_back(stoi(to_string(v[i]) + to_string(v[0])));
    }

    sort(all(b));

    cout << b[2];
}