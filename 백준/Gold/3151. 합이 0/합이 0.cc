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

    int N;
    cin >> N;

    ll A[10101];
    FOR(i, N + 1, 1) cin >> A[i];

    ll ans = 0;
    sort(A + 1, A + 1 + N);

    // 합이 0이 되는 3개의 원소를 출력하면 된다. 어떻게?
    for (int i = 1; i <= N - 2; i++)
    {
        ll req = -A[i];
        
        // 현재 정렬된 상태이다. 즉 합이 -A[i]가 되는 두 정수는 O(N)으로 찾을 수 있을 것이다.
        int j = i + 1;
        int k = N; 
        
        while(j < k)
        {
            ll sum = A[j] + A[k];
            
            // 합이 같음 : 중요 
            if(sum == req) 
            {
                if(A[j] == A[k])
                {
                    ans += (k - j + 1) * (k - j) / 2;
                    break;
                }

                // 같은 개수만큼 개수를 세서 더한다. 
                else 
                {
                    int s = j, e = k;
                    while (A[s] == A[j]) s++;
                    while (A[e] == A[k]) e--;

                    ans += ((s - 1) - j + 1) * (k - (e + 1) + 1);
                    
                    j = s;
                    k = e;
                }
            }
            
            // 합이 더 작음
            else if(sum < req) j++;

            // 합이 더 큼
            else k--;
        }
    }
    
    cout << ans; 
}