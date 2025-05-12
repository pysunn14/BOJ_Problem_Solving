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

    int N; cin >> N;

    vector<int> s;

    FOR(i,N+1,1)
    {
        int x,y; cin >> x >> y;
        vector<int> a;

        FOR(j,5,0)
        {
            int x; cin >> x;
            a.push_back(x);
        }

        sort(all(a));
        s.push_back(max(x,y) + a[4] + a[3]);
    }

    cout << *max_element(all(s));
}