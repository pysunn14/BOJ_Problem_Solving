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
    vector<pii> T(N,{0,0});
    FOR(i,N,0) cin >> T[i].first >> T[i].second;
    sort(all(T));

    ll sum = 0;
    FOR(i,N,0) sum += T[i].second;

    ll cum = 0;
    int i = 0;
    for( ; i < N ; i++)
    {
        cum += T[i].second;
        if(cum >= (sum+1LL)/2LL) break;
    }
    cout << T[i].first;
}