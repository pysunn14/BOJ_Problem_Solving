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

ll A[101010];
ll S[101010];
ll B[101010][31];

int N; 
ll ans;
int main()
{
    fio();

    cin >> N;
    
    FOR(i, N + 1, 1) cin >> A[i];

    FOR(i, N + 1, 1) S[i] = S[i-1] ^ A[i];
    
    FOR(i,N+1,1)
    {
        for(int j = 0 ; j <= 30; j++)
        {
            B[i][j] = B[i-1][j] + ((S[i] & (1 << j)) > 0); 
        }
    }   

    FOR(i,N+1,1)
    {
        int bit[31] = {0};
        // B[i][j] 를 확인해서, 현재 S[i]의 j비트가 0이라면 그대로 넣고 S[i]가 1 이라면 N - B[i][j] 를 넣음. 
        for(int j = 0 ; j <= 30 ; j++)
        {
            if(((S[i] & (1 << j) ) >> j) == 0) bit[j] += B[i-1][j];
            else bit[j] += (i - B[i-1][j]);
        }
        ll loc = 0;
        
        // 자리별로 1의 개수를 저장하면됨 ㅇㅇ 
        FOR(i,31,0) if(bit[i]) loc += (1LL << i) * bit[i];

        ans += loc;
    }
    
    cout << ans;
}