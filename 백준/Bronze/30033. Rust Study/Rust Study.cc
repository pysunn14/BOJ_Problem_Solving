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

    int a[n];
    int b[n];

    FOR(i,n,0) cin >> a[i];
    FOR(i,n,0) cin >> b[i];
    
    int ans = 0;
    FOR(i,n,0) if(a[i] <= b[i]) ans++;
    cout << ans;
}