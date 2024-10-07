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

int hashcode(string s)
{
    int h = 0;

    FOR(i,s.size(),0) h = h * 31 + s[i];

    return h;
}

int main()
{
    fio();

    int N; cin >> N;

    string a = "", b = "";

    if(N % 2 == 0)
    {
        FOR(i,N,0)
        {
            a += 'a';
            if(i % 2 == 0) b += 'b';
            else b += 'B';
        }

        cout << a << '\n';
        cout << b;
    }

    else 
    {
        FOR(i,N-1,0)
        {
            a += 'a';
            if(i % 2 == 0) b += 'b';
            else b += 'B';
        }

        a += 'a';
        b += 'a';

        cout << a << '\n';
        cout << b;
    }
}