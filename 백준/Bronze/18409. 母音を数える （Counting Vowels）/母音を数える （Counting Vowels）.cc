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
    int n; cin >> n;
    string s; cin >> s;
    set<char> t = {'a','e','i','o','u'};

    int c = 0;
    for(int i = 0; i < s.size() ; i++)
    {
        if(t.find(s[i]) != t.end()) c++;
    }
    cout<< c;
}