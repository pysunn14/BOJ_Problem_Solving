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

typedef struct {
    int P;
    int W;
}container; 

int main()
{
    fio();

    int N,M; cin >> N >> M;
    deque<container> dq;

    FOR(i,N,0) 
    {
        int P,W; 
        cin >> P >> W;
        dq.push_back({P,W});
    }

    stack<container> stk;

    // rail
    ll ans = 0;
    while (!dq.empty())
    {
        container now = dq.front();
        dq.pop_front();

        // 높은 순위의 컨테이너
        if(stk.empty())
        {
            if (now.P != M)
            {
                ans += now.W;
                dq.push_back(now);
            }
            else 
            {
                stk.push(now);
                ans += now.W;
            }
        }

        // 아직 now보다 낮은 우선순위의 컨테이너가 모두 적재된 상태가 아니다 
        else 
        {
            bool ok = true;
            // 덱에서 그런 컨테이너가 발견되었음
            FORE(d, dq) if(d.P > now.P) ok = false;

            if(!ok)
            {
                ans += now.W;
                dq.push_back(now);
            }

            // 적재하면 됨.
            else
            {
                // 우선순위 같음 그냥.
                // 무게가 무거운것을 아래로
                vector<container> tmp;
                while (!stk.empty() && stk.top().W < now.W && stk.top().P == now.P)
                {
                    ans += stk.top().W;
                    tmp.push_back(stk.top());
                    stk.pop();
                }
                
                // 지금것 집어넣기
                stk.push(now);
                ans += now.W;

                reverse(all(tmp));
                FORE(c, tmp) 
                {
                    stk.push(c);
                    ans += c.W;
                }
            }

        }
    }

    cout << ans;
}