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

    string S,T; cin >> S >> T;

    // S와 T의 두 앞 공통부분, 두 뒤 공통부분을 덜어내고 남은 T문자열의 길이 출력 
    deque<char> ds;
    FORE(s, S) ds.push_back(s);
    deque<char> dt;
    FORE(t, T) dt.push_back(t);

    while (!ds.empty() && !dt.empty())
    {
        if(ds.front() == dt.front()) 
        {
            ds.pop_front();
            dt.pop_front();
        }
        else break;
    }

    while (!ds.empty() && !dt.empty())
    {
        if(ds.back() == dt.back()) 
        {
            ds.pop_back();
            dt.pop_back();
        }
        else break;
    }

    cout << dt.size();
}