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

    int n; cin >> n;

    vector<ll> m(n);
    FOR(i,n,0) cin >> m[i];

    ll TL = m[0];
    ll TR = m[1];

    ll L = 2*TL - TR, R = m[0];
    ll nL = 0, nR = 0;

    for(int i = 0 ; i < n-1 ; i++)
    {
        ll middle = m[i];

        ll TL = m[i];
        ll TR = m[i+1];

        nL = 2 * middle - L;
        nR = 2 * middle - R; 

        if(nR < nL) 
        {
            ll tmp = nR;
            nR = nL;
            nL = tmp;
        }

        if(nL > TR || nR < TL)
        {
            cout << 0;
            return 0;
        }

        if(nL < TL) L = TL;
        else L = nL;

        if(nR > TR) R = TR;
        else R = nR;
    }

    cout << R - L + 1 << '\n';
}




