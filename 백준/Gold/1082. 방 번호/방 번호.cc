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
    int P[10]; int cnt = 0;
    FOR(i,N,0) cin >> P[i];
    int M; cin >> M;

    int min_nonzero_coin = 1;
    int min_coin = 0;

    int min_value = 99;
    FOR(i,N,0) if(min_value > P[i]) {min_value = P[i]; min_coin = i;}

    min_value = 99;
    FOR(i,N,1) if(min_value > P[i]) {min_value = P[i]; min_nonzero_coin = i;}

    if(M < P[min_nonzero_coin] || N == 1) cout << 0;

    else
    {
        int cc = M - P[min_nonzero_coin];
        // 이제 0원을 얼만큼 살 수 있는지를 확인한다.
        int zz = cc / P[min_coin];
        cnt = zz + 1;

        // solve
        int cur = 0;
        int coin = N-1;

        while(true)
        {
            // 가장 비싼 친구를 구매해도 되는지를 판정한다.
            if(M - P[coin] >= P[min_coin] * (cnt - (cur+1)))
            {
                // 살 수 있으면 구매한다.
                cout << coin;
                cur++;
                M -= P[coin];
                if(M <= 0 || cur >= cnt) break;
            }

            // 사지 못한다면 coin을 하나 낮춘다.
            else coin--;
        }
    }
}