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

ll W[16][16];
int N; 

// 이제 시간복잡도를 줄여야 하는데, 현재 순회하고 있는 상태를 비트로 표현하여 저장하자. 
// 같은 방문 조합인 경우에는 바로 리턴하는 거다.

ll dp[16+1][1<<16]; // now, status

ll TSP(int now, int status)
{
    // 이미 확인한 상태가 있으면 
    if(dp[now][status] != -1) return dp[now][status];
    
    // 모든 도시를 다 방문 : 시작 도시로 
    if(status == (1 << N) - 1) 
    {
        if(W[now][0] == 0) return INT_MAX;
        return W[now][0]; 
    }

    dp[now][status] = INT_MAX;
    
    // 아직 방문하지 않은 도시 중 다음 도시 찾기 
    FOR(next, N, 0)
    {
        // status 에서 next 에 해당되는 비트가 안켜져있어야 하고, 갈 수 있는 곳이어야 함
        if(!(status & (1 << next)) && W[now][next])
        {
            dp[now][status] = min(dp[now][status], W[now][next] + TSP(next, status | (1 << next)));
        }
    }
    
    // 최소를 반환 
    return dp[now][status];
}

int main()
{
    fio();

    cin >> N;

    FOR(i,N,0) FOR(j,1<<16,0) dp[i][j] =  -1;

    FOR(i,N,0)
    {
        FOR(j,N,0)
        {
            cin >> W[i][j];
        }
    }
    
    // 외판원이 어느 한 도시에서 출발해 N개의 도시를 모두 거치고 다시 원래 도시로 돌아오는 비용 -> 최소비용?
    cout << TSP(0, 1);
}