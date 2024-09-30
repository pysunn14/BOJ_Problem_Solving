#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define pp pop_back
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define pll pair<ll, ll>

typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define weight first
#define vertex second
#define all(v) v.begin(), v.end()
using namespace std;

int main()
{
    fio();

    int N; cin>>N;

    ll A[252525]; //2십만
    FOR(i,N,0) cin>>A[i+1];

    ll ans = 0;
    FOR(i,N+1,2)
    {
        if(A[i] >= A[i-1]) continue;

        int lo = 0, hi = 30;
        while (lo + 1 < hi)
        {
            ll mid = (lo+hi)/2;
            if((A[i]*pow(2,mid)) < A[i-1]) lo = mid;
            else hi = mid;
        }

        A[i] *= pow(2,hi);

        ans += hi;
    }
    cout<<ans;
}