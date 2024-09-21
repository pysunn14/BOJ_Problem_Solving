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

    test(T)
    {
        int N; 
        cin>>N;
        vector<int> coins(N,0);
        FOR(i,N,0) cin>>coins[i];
        sort(all(coins));
        int M; cin >> M;

        // i번째 동전까지 생각해서 j원을 만드는 방법의 수
        int d[20][10001] = {0};

        // 첫번째 동전만 사용하기
        FOR(j,M+1,1) if(j >= coins[0] && j % coins[0] == 0) d[0][j] = 1;

        // 1원을 만드는 경우의 수
        FOR(i,N,1)
        {
            FOR(j,M+1,1)
            {
                //i번째 동전을 포함시킬 수 없음
                if(coins[i] > j) d[i][j] = d[i-1][j]; 
                else if(coins[i] == j) d[i][j] = d[i-1][j] + 1;

                //i번째 동전을 포함해서 개수를 셀 수 있는 경우 : i번째 동전을 포함 안하고 구성한 방법수에 더해주기
                else d[i][j] = d[i-1][j] + d[i][j - coins[i]];
            }
        }
        
        cout << d[N-1][M] << '\n';
    }
}