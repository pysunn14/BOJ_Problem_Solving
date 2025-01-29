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

    test(t)
    {
        ll res = 0;
        
        ll S,F; cin >> S >> F;

        // 짝홀 짝홀 개수 구하기

        if(S % 2 == 1) 
        {
            res ^= S;
            S++;
        }

        if(F % 2 == 0)
        {
            res ^= F;
            F--;
        }

        if(S < F)
        {
            if((F/2 - S/2 + 1) % 2 == 1) res ^= 1; 
        }

        cout << res << '\n';
    }
}