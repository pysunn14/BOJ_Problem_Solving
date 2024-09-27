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

set<string> CW_MOVE = {"NE","ES","SW","WN"};
set<string> CCW_MOVE = {"EN","SE","WS","NW"};

int main()
{
    fio();
    int N; cin >> N;

    FOR(i,N,0) // 20
    {
        int cw_cnt = 0;
        int ccw_cnt = 0;
        string s; 
        cin >> s; // 100

        FOR(i,s.size(),0)
        {
            string temp = "";
            if(i == s.size()-1)
            {
                if(s[i] != s[0])
                {
                    temp += s[i];
                    temp += s[i+1];  
                    if(CW_MOVE.find(temp) != CW_MOVE.end()) cw_cnt++;
                    else ccw_cnt++;
                }
            }
            
            if(s[i] != s[i+1])
            {
                temp += s[i];
                temp += s[i+1];

                if(CW_MOVE.find(temp) != CW_MOVE.end()) cw_cnt++;
                else ccw_cnt++;
            }
        }

        if(cw_cnt > ccw_cnt) cout << "CW\n";
        else cout << "CCW\n";
    }
}