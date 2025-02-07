#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define pp pop_back
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
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

ll getRight(int mid, int a, int d)
{
    return (ll)mid*((ll)2*a+(ll)(mid-1)*d)/2;
}

bool check(int mid, int a, int d, int x)
{
    return getRight(mid, a, d) >= x;
}

int main()
{
    fio();

    int q; cin>>q;

    FOR(i,q,0)
    {
        int a,d,x; cin>>a>>d>>x;
        int lo = 0, hi = 99999;
        while (lo + 1 < hi)
        {
            int mid = (lo+hi) / 2;
            if(check(mid, a, d, x)) hi = mid;
            else lo = mid;
        }
        cout<<hi<<" "<<(ll)x-getRight(hi-1,a,d)<<'\n';
    }
}


