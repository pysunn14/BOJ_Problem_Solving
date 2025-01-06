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
    vector<pii> a(N);
    FOR(i,N,0) cin >> a[i].first >> a[i].second;

    sort(all(a),[](pii x, pii y){
        if(x.first == y.first) return x.second < y.second;
        return x.first > y.first;
    });

    int score = a[4].first;

    int ans = 0;
    FOR(i,a.size(),5)
    {
        if(a[i].first == score)
        {
            ans++;
        }
    }
    cout << ans;
}