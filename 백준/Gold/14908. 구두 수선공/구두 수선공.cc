#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pii pair<double, double>
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

    vector<pair<pii, int>> j;

    FOR(i,N+1,1)
    {
        int T,S; cin >> T >> S;
        j.push_back({{T,S},i});
    }

    sort(all(j), 
    [](pair<pii,int> a, pair<pii,int> b){ 
        if(a.first.second / a.first.first == b.first.second / b.first.first)
        return a.second < b.second;

        return a.first.second / a.first.first > b.first.second / b.first.first;
    });

    FORE(e, j) cout << e.second << ' ';
}