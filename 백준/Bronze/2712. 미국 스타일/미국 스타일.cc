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

    cout << fixed;
    cout.precision(4);

    test(T)
    {
        long double value;
        string SI;

        cin >> value >> SI;

        if(SI == "kg")
        {
            cout << value * 2.2046 << " lb\n";
        }

        else if(SI == "l")
        {
            cout << value * 0.2642 << " g\n";
        }

        else if(SI == "lb")
        {
            cout << value * 0.4536 << " kg\n";
        }

        else
        {
            cout << value * 3.7854 << " l\n";
        }
    }
}