#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fio()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const ll mod = 1e9 + 7;

ll ans;
ll cost[1000*1000 + 1];
ll cur[1000*1000 + 1];
int A[1010][1010];
int level[1010][1010];

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

int N,M,C; 

void bfs(int SR, int SC)
{
    queue<pair<int,int>> q;
    q.push({SR,SC});
    level[SR][SC] = 0;

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int t = 0 ; t < 4; t++)
        {
            int nr = r + dr[t];
            int nc = c + dc[t];

            // 갈 수 있는 곳이면
            if(level[nr][nc] == -1 && A[nr][nc] != -1)
            {
                q.push({nr,nc});
                level[nr][nc] = level[r][c] + 1;
            }
        }
    }
}

int main()
{
    fio();
    cin >> N >> M >> C;
    int SR, SC; 
    cin >> SR >> SC;


    // level초기화
    for(int i = 0 ; i < 1010; i++)
    {
        for(int j = 0 ; j < 1010; j++)
        {
            A[i][j] = -1;
            level[i][j] = -1;
        }
    }

    for(int i = 1 ; i <= N; i++)
    {
        for(int j = 1 ; j <= M; j++)
        {
            cin >> A[i][j];
        }
    }
    
    bfs(SR,SC);

    // cost 정산
    for(int i = 1 ; i <= N; i++)
    {
        for(int j = 1 ; j <= M; j++)
        {
            if(A[i][j] != -1) cur[level[i][j]] += A[i][j]; 
        }
    }

    cost[0] = cur[0];
    for(int i = 1 ; i < 1000*1000+1; i++) cost[i] = cost[i-1] + cur[i];
    for(int i = 0 ; i < 1000 * 1000; i++) cost[i] -= i * C;

    cout << *max_element(cost, cost+1000*1000);
}