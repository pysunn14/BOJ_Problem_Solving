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

    int N; cin >> N;

    vector<int> a(N);
    FOR(i,N,0) cin >> a[i];

    // 인접 합 중에서 합이 제일 작아지는 두 원소를 합치기 . 합이 같으면 최대 원소값이 좀더 작은 케이스로 설정하기.
    ll ans = 0;
    int iter = 0;

    while (iter < N - 1)
    {  
        int sum = INT_MAX;
        int idx = 0;
        int max_a = INT_MAX;
        
        FOR(i, N - iter - 1, 0)
        {
            if(a[i] + a[i+1] < sum && max(a[i], a[i+1]) < max_a)
            {
                idx = i;
                sum = a[i] + a[i+1];
                max_a = max(a[i], a[i+1]);
            }
        }
        
        ans += (a[idx] + a[idx+1]);
        
        a[idx] = max_a;
        a.erase(a.begin() + idx + 1);

        iter++;
    }   
    
    cout << ans;
}