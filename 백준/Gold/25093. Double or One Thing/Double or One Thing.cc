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

    test(T)
    {
        string s; 
        cin >> s;

        string ans = "";

        for(int i = 0 ; i < s.size() ; i++)
        {
            ans += s[i];
            int j = i + 1;
            while (j < s.size() && s[j] == s[i]) j++;
            if(s[j] > s[i]) ans += s[i];
        }

        cout << "Case #" << T+1 <<": " << ans << '\n'; 
    }
}