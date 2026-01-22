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

ll A[1010101];

int main()
{
    fio();

    int N; cin >> N;

    // 순서를 바꾼뒤에 인접차의 최대는 어떻게 구할거냐? 
    FOR(i,N+1,1) cin >> A[i];

    sort(A+1,A+N+1);

    ll ans = 0;

    int turn = 0;

    int i = 2;
    int j = N;

    deque<ll> dq; 

    dq.push_back(A[1]);
    
    while(i <= j)
    {
        ll left = dq.front();
        ll right = dq.back(); 

        // 작은거 붙이면 더 큼 
        if(max(llabs(left - A[i]), llabs(right - A[i])) >= max(llabs(left - A[j]), llabs(right - A[j])))
        {

            if(llabs(left - A[i]) > llabs(right - A[i]))
            {
                dq.push_front(A[i]);
                ans += llabs(left - A[i]);
            }

            else 
            {
                dq.push_back(A[i]);
                ans += llabs(right - A[i]);
            }
            i++;
        }
        
        // j 움직이기 
        else 
        {
            if(llabs(left - A[j]) > llabs(right - A[j]))
            {
                dq.push_front(A[j]);
                ans += llabs(left - A[j]);
            }

            else 
            {
                dq.push_back(A[j]);
                ans += llabs(right - A[j]);
            }

            j--; 
        } 
        
        turn++;
    }
    cout << ans;

}