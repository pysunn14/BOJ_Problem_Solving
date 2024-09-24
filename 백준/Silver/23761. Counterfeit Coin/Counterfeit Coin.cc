#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define test(a) \
    int _;      \
    cin >> _;   \
    FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

int main()
{
    fio();
    int n;
    cin >> n;

    string ans;
    if (n % 2 == 0)
    {
        for (int i = 1; i + 1 <= n; i += 2)
        {
            if (i < n - 1)
            {
                cout << "? " << i << ' ' << i + 1 << endl;
                cin >> ans;

                if (ans == "equal")
                    continue;

                cout << "? " << i << ' ' << i + 2 << endl;
                cin >> ans;

                if (ans == "equal")
                    cout << "! " << i + 1 << endl;
                else
                    cout << "! " << i << endl;
                return 0;
            }

            else if (i == n - 1)
            {
                cout << "? " << i << ' ' << i - 1 << endl;
                cin >> ans;
                if (ans == "equal")
                    cout << "! " << i + 1 << endl;
                else
                    cout << "! " << i << endl;
                return 0;
            }
        }
        cout << "! " << n << endl;
    }

    else
    {
        int i;
        for (i = 1; i + 2 < n; i += 2)
        {
            if (i < n - 1)
            {
                cout << "? " << i << ' ' << i + 1 << endl;
                cin >> ans;

                if (ans == "equal")
                    continue;
                cout << "? " << i << ' ' << i + 2 << endl;
                cin >> ans;

                if (ans == "equal")
                    cout << "! " << i + 1 << endl;
                else
                    cout << "! " << i << endl;
                return 0;
            }
        }

        cout << "? " << i << ' ' << i + 1 << endl;
        cin >> ans;
        int v;

        if(ans == "equal") v = i + 2;
        else
        {
            cout << "? " << i << ' ' << i + 2 << endl;
            cin >> ans;
            if(ans == "equal") v = i + 1;
            else v = i;
        }
        cout << "! " << v << endl;
    }
}