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

ll ans;
int N,M; 

int A[1010][1010];
int L[1010][1010];
int R[1010][1010];

int dr[4] = {0,0,-1,1}; // R L U D
int dc[4] = {1,-1,0,0};

bool vis[1010][1010];

// 각 위치마다에 대해서 남아있는 L,R 이동가능 횟수를 저장하면서 생각하면 되지 않을까? 
void bfs(int SR, int SC)
{
    queue<pii> q;
    q.push({SR,SC});
    vis[SR][SC] = true;

    while (!q.empty())
    {
        // 각 칸을 가기 위해서 요구되는 L과 R을 저장해준다.
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        FOR(t,4,0)
        {
            int nr = r + dr[t];
            int nc = c + dc[t];

            if(A[nr][nc] == 1 || vis[nr][nc]) continue;

            // R
            if(t == 0) 
            {
                if(R[r][c] < 1) continue;
                L[nr][nc] = L[r][c];
                R[nr][nc] = R[r][c] - 1;

                q.push({nr,nc});
                vis[nr][nc] = true;
            }

            // L
            else if(t == 1) 
            {
                if(L[r][c] < 1) continue;
                L[nr][nc] = L[r][c] - 1;
                R[nr][nc] = R[r][c];

                q.push({nr,nc});
                vis[nr][nc] = true;
            }

            // UP, DOWN 
            else
            {
                //계속 가서 푸시
                while (A[nr][nc] != 1 && !vis[nr][nc])
                {
                    L[nr][nc] = L[r][c];
                    R[nr][nc] = R[r][c];
                    q.push({nr,nc});
                    vis[nr][nc] = true;

                    //move
                    nr += dr[t];
                    nc += dc[t];
                }
            }
        }
    }
}

int main()
{
    fio();

    int SR, SC; 
    cin >> N >> M;
    int LL, RR ; cin >> LL >> RR;

    FOR(i,1010,0) FOR(j, 1010, 0) A[i][j] = 1;

    FOR(i,N+1,1)
    {
        string s; cin >> s;
        FOR(j, M+1, 1)
        {
            A[i][j] = s[j-1] - '0';
            if(A[i][j] == 2)
            {
                SR = i;
                SC = j;
                L[i][j] = LL;
                R[i][j] = RR;
            }
        }
    }

    bfs(SR,SC);

    FOR(i,N+1,1) FOR(j, M+1, 1) if(vis[i][j]) ans++;
    cout << ans;
}