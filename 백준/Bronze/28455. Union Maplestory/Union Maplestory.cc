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
    int sum = 0;
    int s = 0;
    vector<int> uni;

    FOR(i,N,0)
    {
        int x; cin >> x;
        uni.push_back(x);

    }
    sort(all(uni));
    reverse(all(uni));

    for(int i = 0 ; i < 42 && i < N; i++)
    {
        int x = uni[i];
        sum += x;
        if(x >= 60) s++;
        if(x >= 100) s++;
        if(x >= 140) s++;
        if(x >= 200) s++;
        if(x >= 250) s++;
    }

    cout << sum << ' ' << s;
}