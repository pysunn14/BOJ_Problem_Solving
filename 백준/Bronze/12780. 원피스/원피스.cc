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

    string h; cin >> h;
    string n; cin >> n;

    // h안에 n이 몇 번 등장하는가? 
    int ans = 0;
    for (int i = 0; i < h.size() - n.size() + 1; i++) if (h.substr(i, n.size()) == n) ans++;
    cout << ans;
}