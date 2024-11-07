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

    int N,K; 
    cin >> N >> K;
    int T[101010];
    FOR(i,N,0) cin >> T[i];

    if(N == 1) 
    {
        cout << 1;
        return 0;
    }

    vector<int> diff;

    FOR(i,N-1,0)
    {
        diff.push_back(T[i+1]-T[i]);
    }

    sort(all(diff));
    reverse(all(diff));

    ll sum = 0 ;
    sum += K;
    FOR(i,N,K-1)
    {
        sum += diff[i];
    }

    cout << sum;
    // T는 항상 증가수열이다.
}