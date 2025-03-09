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

ll P[101];
ll ans;
int main()
{
    fio();

    int M; cin >> M;

    FOR(i,M+1,1) cin >> P[i];

    FOR(i,M+1,1)
    {
        if(P[i] == 2) ans ^= 0;
        else if(P[i] % 2 == 1) ans ^= (P[i] / 2 + 1);
        else ans ^= (P[i] / 2 - 1);
    }

    if(ans) cout << "koosaga";
    else cout << "cubelover";
}