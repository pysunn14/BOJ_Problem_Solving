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

int a[5050505];
int main()
{
    fio();

    int n; cin >> n;

    FOR(i,n+1,1) cin >> a[i];

    int ans = 1;
    FOR(i,n+1,2) 
    {
        if(a[i] >= a[i-1]) ans++;
    }
    cout << ans;
}