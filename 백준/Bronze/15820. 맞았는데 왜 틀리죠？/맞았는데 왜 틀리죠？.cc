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

    int S1,S2;
    cin >> S1 >> S2;

    FOR(i,S1,0)
    {
        int a,b; cin >> a >> b;
        if(a!=b)
        {
            cout << "Wrong Answer";
            return 0;
        }
    }

    FOR(i,S2,0)
    {
        int a,b; cin >> a >> b;
        if(a!=b)
        {
            cout << "Why Wrong!!!";
            return 0;
        }
    }
    
    cout << "Accepted";
    
}