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

int A[1010];
int main()
{
    fio();

    int N,T; 
    cin >> N >> T;

    FOR(i,N,0)
    {
        int K; 
        cin >> K;
        FOR(j,K,0)
        {
            int S,E;
            cin >> S >> E; 
            FOR(k,E,S) A[k]++;
        }
    }

    int now = 0;
    FOR(i,T,0) now += A[i];

    int ans = now;
    int ANS_S = 0, ANS_E = T-1;

    // T시간씩 스위핑하면서 최대인 부분을 찾기.
    for(int i = 1, j = i+T-1 ; j < 1010 ; i++, j++)
    {
        now += A[j];
        now -= A[i-1];

        if(now >  ans)
        {
            ANS_S = i;
            ANS_E = j;
            ans = now;
        }
    }

    cout << ANS_S << " " << ANS_E + 1;
    // cout << ans;
}