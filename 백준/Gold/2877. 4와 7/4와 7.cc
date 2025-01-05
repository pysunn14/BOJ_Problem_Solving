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

    int K; cin >> K;
    int i = 2;
    while (i <= K)
    {
        K -= i;
        i *= 2;
    }

    if(K == 0) 
    {
        i /= 2;
        for(int b = 0 ; b < log2(i); b++) cout << 7;
        return 0;
    }

    else K--;

    vector<int> v;
    for(int b = 0 ; b < log2(i); b++)
    {
        int now = (K & (1<<b)) >> b;
        if(now == 1) v.push_back(7);
        else v.push_back(4);
    }

    reverse(all(v));

    FORE(vv, v) cout << vv;
}