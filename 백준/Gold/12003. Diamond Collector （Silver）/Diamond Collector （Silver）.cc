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

    ll N,K; cin >> N >> K;

    ll A[50505];
    FOR(i,N+1,1) cin >> A[i];
    sort(A + 1, A + 1 + N);

    int cnt[50505];
    int s[50505] = {0};
    
    // 각 A[i]에 대해서 최대 차이 K 이하로 몇번째까지 선택이 가능한가 저장
    FOR(i,N,1)
    {
        auto it = upper_bound(A + 1, A + 1 + N, A[i] + K);
        int idx = distance(A + 1, it);
        cnt[i] = idx;
    }
    cnt[N] = N;

    s[N] = 1;
    for(int i = N - 1 ; i >= 1; i--) s[i] = max(s[i+1], cnt[i] - i + 1);

    ll mx = 0 ;

    FOR(i,N,1)
    {
        // cnt[i] 이후 가장 커지는 값에 대해서 합산해서 출력. 
        ll ret = cnt[i] - i + s[cnt[i]+1];
        mx = max(mx, ret); 
    }
    
    cout << mx + 1; 
}

