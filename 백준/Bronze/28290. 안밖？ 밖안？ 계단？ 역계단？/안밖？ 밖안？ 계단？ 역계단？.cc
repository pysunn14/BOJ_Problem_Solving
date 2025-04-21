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

map<string, string> m;

int main()
{
    fio();
    m["fdsajkl;"] = "in-out";
    m["jkl;fdsa"] = "in-out";
    m["asdf;lkj"] = "out-in";
    m[";lkjasdf"] = "out-in";
    m["asdfjkl;"] = "stairs";
    m[";lkjfdsa"] = "reverse";
    string s; cin >> s;
    
    if(m[s] == "") cout << "molu";
    else cout << m[s];
}