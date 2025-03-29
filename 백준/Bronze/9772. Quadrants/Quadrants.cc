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

    while (true)
    {
        double x,y; cin >> x >> y;
        if(x == 0 && y == 0) 
        {
            cout << "AXIS\n";
            break;
        }

        if(x == 0 || y == 0) cout << "AXIS\n";

        else if(x > 0 && y > 0) cout << "Q1\n";

        else if(x > 0 && y < 0) cout << "Q4\n";

        else if(x < 0 && y < 0) cout << "Q3\n";

        else cout << "Q2\n";
    }
    
}