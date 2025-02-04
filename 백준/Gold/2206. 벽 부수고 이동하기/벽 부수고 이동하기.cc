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

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

bool a[1010][1010];

int min_dist = INT_MAX;

void bfs(int sr, int sc, int er, int ec, int dist[1010][1010])
{
    queue<pii> q;
    q.push({sr,sc});
    dist[sr][sc] = 1;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for(int t = 0 ; t < 4; t++)
        {
            int nr = r + dr[t];
            int nc = c + dc[t];
            if(a[nr][nc] || dist[nr][nc]) continue;

            q.push({nr,nc});
            dist[nr][nc] = dist[r][c] + 1;
        }
    }    
    if(dist[er][ec]) min_dist = dist[er][ec];
}

int main()
{
    fio();

    FOR(i,1010,0) FOR(j,1010,0) a[i][j] = 1;

    int dist[1010][1010] = {0};
    int rev_dist[1010][1010] = {0};

    int N,M; cin >> N >> M;

    FOR(i,N+1,1)
    {
        string s; 
        cin >> s;
        FOR(j,M+1,1)
        {
            char token = s[j-1];
            if(token == '0') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }

    // 일단 벽을 부수지 않고 갔을 때 거리를 저장함.   
    bfs(1,1,N,M,dist);
    bfs(N,M,1,1,rev_dist);


    FOR(i,N+1,1)
    {
        FOR(j,M+1,1)
        {
            if(dist[i][j] == 0) continue;

            // 네방향
            for (int t = 0; t < 4; t++)
            {
                // 인접칸이 벽인 경우 부순 거리 체크하기
                int r = i + dr[t];
                int c = j + dc[t];

                if(a[r][c] == 0) continue;

                // 벽을 기준으로 꺾은 부분 체크하기

                for(int k = 0; k < 4; k++)
                {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // 다음 칸이 도달 가능해야하고 거리값이 있어야 함
                    if (nr < 1 || nc < 1 || nr > N || nc > M || rev_dist[nr][nc] == 0) continue;
                    min_dist = min(1 + rev_dist[nr][nc] + dist[i][j], min_dist);
                }
            }
        }
    }
    
    if(min_dist == INT_MAX) min_dist = -1;
    cout << min_dist;
}