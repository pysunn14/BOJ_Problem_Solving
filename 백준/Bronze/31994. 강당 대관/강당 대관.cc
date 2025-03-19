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

    vector<pair<int,string>> v;

    FOR(i,7,0)
    {
        string name; int value;
        cin >> name >> value;

        v.push_back({value, name});
    }

    sort(all(v));

    cout << v.back().second;
    
}