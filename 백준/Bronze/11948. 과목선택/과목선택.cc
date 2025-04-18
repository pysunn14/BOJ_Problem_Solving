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

    int a,b,c,d,e,f;

    cin >> a >> b >> c >> d >> e >> f;

    // a,b,c,d 중에서 3개를 고르고 d,e에서 하나 고름 

    cout << a+b+c+d - min({a,b,c,d}) + max(e,f);
}