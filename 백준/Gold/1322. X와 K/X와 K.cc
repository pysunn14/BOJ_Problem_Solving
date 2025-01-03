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

// ll Y;
int main()
{
    fio();

    ll X, K; cin >> X >> K;

    vector<int> zero_pos;
    // K를 이진수화 해서 비트로 표현하고, 그 비트들을 X에서 0의 위치에 있던 자리에 다 넣는다.

    vector<bool> bit;
    for(int i = 0, j = 0 ; (1LL<<j) <= K; i++)
    {
        if(((X & (1LL<<i)) >> i) == 1) bit.push_back(0);
        else 
        {
            bit.push_back((K & (1LL<<j)) >> j);
            j++;
        }
    }
    
    ll ans = 0;
    for(int k = 0 ; k < bit.size(); k++)
    {
        if(bit[k]) ans += (1LL<<k);
    }
    cout << ans;
}