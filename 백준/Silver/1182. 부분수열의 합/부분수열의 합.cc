#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define test(a) int _; cin >> _; FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define weight first
#define vertex second
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;


// 14 = 1110(2)

int main()
{
    fio();

    int N,S; cin >> N >> S;

    int A[21];
    FOR(i,N,0) cin >> A[i];

    ll ans = 0;
    int bit = 0;

    while(bit < (1 << N))
    {
        ll sum = 0;
        FOR(i,N,0) if((bit >> i) & 1) sum += A[i];
        if(sum == S) ans++;
        bit++;
    }
    if(!S) ans--;
    cout << ans;
}