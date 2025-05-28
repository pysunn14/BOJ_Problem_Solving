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

    string s; 

    getline(cin, s);

    if(s == "1 2 3 4 5 6 7 8") cout <<"ascending";

    else if(s == "8 7 6 5 4 3 2 1") cout << "descending";

    else cout << "mixed";
}