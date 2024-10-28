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

    int N; cin >> N;

    int p[101010], t[101010];

    int a[101010];

    FOR(i,N+1,1) cin >> p[i];
    FOR(i,N+1,1) cin >> t[i];

    // 연속적인 칸막이들에 대해서 온도를 1씩 올릴수도 있고, 내릴 수도 있다 

    // 이 명령을 최소한만 사용해서 온도를 원하는 온도로 맞춘다.

    // 현재 온도는 t 온도이고 이 명령을 잘 써서 모두 p온도로 맞춘다. 

    FOR(i,N+1,1) a[i] = p[i] - t[i];

    ll ans = 0;
    // 구분하기
    FOR(i,N+1,1)
    {
        if(!a[i]) continue;

        if(a[i] > 0)
        {
            vector<int> s;
            s.push_back(a[i]);
            i++;

            while (i <= N)
            {
                if(a[i] > 0) s.push_back(a[i]);
                else 
                {
                    i--;
                    break;
                }
                i++;
            }
            ans += s[0];
            for(int t = 1 ; t <= s.size() - 1; t++) if(s[t] >= s[t-1]) ans += s[t] - s[t-1];
        }

        else if(a[i] < 0)
        {
            vector<int> s;
            s.push_back(-a[i]);
            i++;

            while (i <= N)
            {
                if(a[i] < 0) s.push_back(-a[i]);
                else 
                {
                    i--;
                    break;
                }
                i++;
            }
            ans += s[0];
            for(int t = 1 ; t <= s.size() - 1; t++) if(s[t] >= s[t-1]) ans += s[t] - s[t-1];
        }
    }
    cout << ans;
}