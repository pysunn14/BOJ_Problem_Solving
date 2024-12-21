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

    set<char> upper = {'R','O','Y','G','B','I','V'};
    set<char> lower = {'r','o','y','g','b','i','v'};

    for(int i = 0 ; i < s.size(); i++)
    {
        if(upper.find(s[i]) != upper.end())
        {
            upper.erase(s[i]);
        }

        else if(lower.find(s[i]) != lower.end())
        {
            lower.erase(s[i]);
        }
    }
    
    if(!upper.empty() && !lower.empty()) cout << "NO!";
    else if(upper.empty() && lower.empty()) cout << "YeS";
    else if(upper.empty()) cout << "YES";
    else cout << "yes";
}