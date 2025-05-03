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

    test(t)
    {
        int n; cin >> n;
        ll a[202020] = {0};
        ll d[202020] = {0};
        FOR(i,n+1,1) cin >> a[i];
        FOR(i,n+1,1) d[i] = a[1] - a[i];

        // 증감이나 감증을 바꿔야 이득보긴함. 
        // 일단 2번을 1번으로 바꿨을때를 세고. 
        ll ans = 0;
        FOR(i,n+1,3) ans += llabs(d[i] - d[i-1]);
        
        // 가장 좌우차가 줄어드는 수로 바꿀 때 
        ll diff = 0;
        int idx = -1;

        FOR(i,n,2)
        {
            if(a[i-1] <= a[i] && a[i] <= a[i+1]) continue;
            if(a[i-1] >= a[i] && a[i] >= a[i+1]) continue;
            if(diff < llabs(a[i] - a[i+1]) + llabs(a[i] - a[i-1]) - llabs(a[i+1] - a[i-1]))
            {
                diff = llabs(a[i] - a[i+1]) + llabs(a[i-1] - a[i]) - llabs(a[i+1] - a[i-1]);
                idx = i;
            }
        }
        
        // 마지막 
        if(diff <= llabs(a[n] - a[n-1]))
        { 
            idx = n;
        }

        a[idx] = a[idx-1];   
        FOR(i,n+1,1) d[i] = a[1] - a[i];
        ll ans2 = llabs(d[2]);

        FOR(i,n+1,3)
        {
            ans2 += llabs(d[i] - d[i-1]);
        }
        
        cout << min(ans, ans2) << '\n'; 
    }
}   