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

int a[101][101];

int main()
{
    fio();

    int n; cin >> n;

    while(n--)
    {
        int x, y; cin >> x >> y;

        for(int i = 90-y ; i < 100-y; i++)
        {
            for(int j = x ; j < x + 10 ; j++)
            {
                if(i >= 0 && i < 101 && j >= 0 && j < 101) a[i][j] = 1; // 
            }
        }
    }

    int count = 0;
    for(int i = 0 ; i < 101 ; i++)
    {
        for(int j = 0 ; j < 101 ; j++)
        {
            count += a[i][j];
        }
    }
    cout << count;
}