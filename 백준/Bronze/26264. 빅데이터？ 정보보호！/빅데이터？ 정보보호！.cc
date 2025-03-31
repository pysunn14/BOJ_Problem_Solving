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

    int bb = 0, ss = 0;
    FOR(i,s.size(),0)
    {
        if(s[i] == 'b') bb++;
        else if(s[i] == 's') ss++;
    }

    if(bb > ss) cout << "bigdata?";
    else if(ss > bb) cout << "security!";
    else cout << "bigdata? security!";
}