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

int main()
{
    fio();

    int n; cin >> n;
    int A[101010];
    FOR(i,n+1,1) cin >> A[i];

    // 음수 있으면 두개씩 제거하기

    // 양수는 무조건 양수끼리 제거하기 

    // 음수랑 양수가 둘다 홀수 일수도 있음.. 그러면 따로따로하는게 제일 나음 

    // 0이 있으면 음수랑 결합시키면 좋음. 

    ll ans = 0;

    priority_queue<int> p;
    priority_queue<int> m;

    // 1 3 5 7

    FOR(i,n+1,1)
    {
        if(A[i] > 0) p.push(A[i]);
        else m.push(-A[i]);

    }

    while (!p.empty())
    {
        int a = p.top(); p.pop();
        if(a == 1)
        {
            ans++;
            continue;
        }
        int b;
        if(!p.empty())
        {
            b = p.top(); p.pop();
            ans += (ll)a*(ll)b;
            if(b == 1) ans++;
        }

        else ans += a;
    }

    while (!m.empty())
    {
        int a = -m.top(); m.pop();
        int b;
        if(!m.empty())
        {
            b = -m.top(); m.pop();
            ans += (ll)a*(ll)b;
        }

        else ans += a;
    }
    

    cout << ans;
}