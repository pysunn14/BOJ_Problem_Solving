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

int s[1010101];
int main()
{
    fio();

    int n; cin >> n;
    s[1] = 0;

    FOR(i,1000001,2)
    {
        ll sum = 0;
        for(int j = 1; j * j <= i; j++)
        {
            int a = j;
            int b = i / j;

            if(i % a == 0)
            {
                sum += a;
                if(a != b && b != i)
                {
                    sum += b;
                }
            }
        }

        if(sum == i) s[i] = 1;
        else if(sum < i) s[i] = 0;
        else s[i] = 2;
    }

    FOR(i,n,0)
    {
        int x; cin >> x;

        if(s[x] == 2) cout << "abundant\n";
        else if(s[x] == 1) cout << "perfect\n";
        else cout << "deficient\n";
    }
}