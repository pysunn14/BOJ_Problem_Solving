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

    int X,Y,Z; cin >> X >> Y >> Z;

    if(X <= 2 || Y <= 2 || Z <= 2) cout << 0;
    
    else 
    {
        if(X == 3 && Y == 3 && Z == 3) cout << 0;
        
        else 
        {
            int M = min({X,Y,Z});
            cout << (M / 2) - (M % 2 == 0); 
        }
    }
}