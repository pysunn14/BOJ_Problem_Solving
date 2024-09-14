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

ll SA[1001]; 
ll SB[1001];

int main()
{
    fio();

    ll T; cin>>T;

    int n; cin>>n;
    int A[1001]; FOR(i,n+1,1) cin>>A[i]; //1000
    SA[1] = A[1]; FOR(i,n+1,2) SA[i] = SA[i-1] + A[i];

    int m; cin>>m; // 1000
    int B[1001]; FOR(i,m+1,1) cin>>B[i];
    SB[1] = B[1]; FOR(i,m+1,2) SB[i] = SB[i-1] + B[i];

    ll ans = 0;

    vector<ll> sumA;
    vector<ll> sumB;
    
    //n*n
    FOR(i,n+1,1) FOR(j,n+1,i) sumA.push_back(SA[j] - SA[i-1]);
    FOR(i,m+1,1) FOR(j,m+1,i) sumB.push_back(SB[j] - SB[i-1]);

    sort(all(sumA));
    sort(all(sumB));

    FORE(sa, sumA)
    {
        ll cntB = ub(all(sumB), T-sa)-lb(all(sumB), T-sa);
        ans += cntB;
    }

    //output
    cout<<ans;
}