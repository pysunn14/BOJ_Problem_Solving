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

ll ans;
ll K; 
ll N; 
ll A[101010]; 
ll M;
ll mx;
ll cnt;
int main()
{
    fio();

    cin >> N;
    FOR(i,N+1,1) cin >> A[i];
    cin >> K;    
    
    mx = A[1];
    FOR(i,N+1,2)
    {
        if(A[i] < mx) M = i;
        else mx = A[i];
    }

    mx = *max_element(A+1,A+1+M);
    FOR(i,M+1,1) cnt += (mx - A[i]);

    if(!M) 
    {
        M = 1;
        mx = A[1];
        cnt = 0;
    }

    else
    {
        if(K >= cnt)
        {
            K -= cnt;
            ans++;

            if(K <= 0) 
            {
                cout << 1;
                return 0;
            }
        }
        
        else 
        {
            cout << 0;
            return 0;
        }
    }
    
    FOR(i, N+1, M+1)
    {
        ll need = (A[i] - mx) * M;
        if(K >= need) 
        {
            K -= need;
            M++;
            if(need > 0) ans += (A[i] - mx);
        }
        
        else 
        {
            ans += K / M;
            cout << ans;
            return 0;
        }
        mx = max(mx, A[i]);
    }

    if(K >= N) ans += (K / N);
    cout << ans;

    return 0;
}

