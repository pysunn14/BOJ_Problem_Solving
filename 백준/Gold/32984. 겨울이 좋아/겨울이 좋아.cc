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

ll A[202020];
ll B[202020];

ll ans = INT_MAX;
int N; 

bool check(ll x)
{
    ll S = 0;

    FOR(i,N+1,1)
    {
        double ratio = (double) A[i] / (double) B[i];
        
        if(ratio <= x) continue; 

        S += ceil(ratio - x);
    }
    
    if(S > x) return false;
    
    // update
    ans = min(ans, x);
    return true;
} 

int main()
{
    fio();

    cin >> N;
    
    FOR(i,N+1,1) cin >> A[i];
    FOR(i,N+1,1) cin >> B[i];
    
    ll lo = 0;
    ll hi = 1e9;

    while (lo + 1 < hi)
    {
        if(check(mid)) hi = mid;
        else lo = mid;
    }
    
    cout << ans;
}