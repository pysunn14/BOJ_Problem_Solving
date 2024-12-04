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

    int N; cin >> N;

    ll ans = 0;

    string s; cin >> s;

    int i = 0;
    while(i < s.size())
    {
        ll cnt = 0;
        if(s[i] == '1')
        {
            int j = i;
            while (j < s.size() && s[j] == '1')
            {
                cnt++;
                j++;
            }
            
            ans += cnt*(cnt+1)/2;
            cnt = 0;
            i = j;
        }

        else i++;
    }

    cout << ans;
}