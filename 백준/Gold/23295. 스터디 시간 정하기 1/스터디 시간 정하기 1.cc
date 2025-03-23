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

ll imos[101010];
ll S[101010];
ll sz = 101010;
int main()
{
    fio();

    int N, T; cin >> N >> T;

    FOR(i,N+1,1) 
    {
        int K, s, e; cin >> K;

        FOR(j,K,0)
        {
            cin >> s >> e;
            imos[s]++;
            imos[e]--;
        }
    }
    
    // 누적합 
    FOR(i,sz,1) imos[i] = imos[i-1] + imos[i];

    S[0] = imos[0];
    FOR(i,sz,1) S[i] = S[i-1] + imos[i];
    
    // sweeping
    ll t = 0;

    // 초기 개수 설정 
    ll mx = S[T - 1];
    ll sum = 0;
    
    int i = 1;
    for( ; i < sz ; i++)
    {
        sum = S[i + T - 1] - S[i - 1];

        // update
        if(sum > mx)
        {
            t = i;
            mx = sum;
        }
    }
    
    cout << t << ' ' << t + T<< '\n';
}