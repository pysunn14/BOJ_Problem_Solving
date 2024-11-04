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

    ll N,K; cin >> N >> K;

    if(K >= N) 
    {
        cout << 0;
        return 0;
    }

    ll div = 1<<23;
    ll ans = 0;
    int cnt = 0;

    while (N)
    {
        if(div <= N)
        {
            cnt++;
            N -= div;

            if(cnt == K && N)
            {
                ans = div - N;
                N = 0;
                break;
            }
        }

        div /= 2;
    }
    
    cout << ans;
}