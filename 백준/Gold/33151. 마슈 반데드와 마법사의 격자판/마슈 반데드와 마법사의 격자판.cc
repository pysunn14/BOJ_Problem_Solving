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

int A[1010][1010];
int main()
{
    fio();

    ll N, K, S1, S2; 
    
    cin >> N >> K;

    // K개의 동전을 적절하게 배치하여 인접노드마다 차이가 1씩 되도록 제작?
    S1 = (N * N) / 2;
    S2 = (N * N) / 2 + (N % 2 == 1);

    // 불가능
    if(S1 > K) 
    {
        cout << -1;
        return 0;
    }

    // N=1
    if(N == 1)
    {
        cout << K;
        return 0;
    }

    int ANS = 0;
    int rem = 0;
    
    bool toggle = 0;
    for(int i = 0 ; i <= K ; i++)
    {
        ll now = S1 * i + S2 * (i + 1);
        rem = K - now;
        if(now <= K && K <= now + S1*2)
        {
            if((K - now) % 2 == 0)
            {
                ANS = i;
                break;
            } 
        }
        
        now = S1 * (i+1) + S2 * i;
        rem = K - now;
        if(now <= K && K <= now + S2*2)
        {
            if((K - now) % 2 == 0)
            {
                ANS = i;
                toggle = !toggle;
                break;
            }
        }
    }
    
    for(int i = 1 ; i <= N; i++)
    {
        for(int j = 1 ; j <= N; j++)
        {
            toggle = !toggle;
            if(toggle) 
            {
                A[i][j] = ANS + 1;
            }
            else 
            {
                A[i][j] = ANS;
                if(rem)
                {
                    A[i][j] += 2;
                    rem -= 2;
                }
            }
        }
        if(N % 2 == 0) toggle = !toggle;
    }

    ll ans = 0;
    // check
    FOR(i,N+1,1)
    {
        FOR(j,N+1,1)
        {
            ans += A[i][j];
        }
    }

    if(ans != K)
    {
        cout << -1 << '\n';
        return 0;
    }

    // output
    FOR(i,N+1,1)
    {
        FOR(j,N+1,1)
        {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}