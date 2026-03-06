#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

#define fio(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int A[131][131];
int N; 

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int di()
{
    int dis[131][131];

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            dis[i][j] = 1e9;
        }
    }

    priority_queue<pair<int,pii>> pq; // dist, node 

    dis[0][0] = A[0][0];
    pq.push({-A[0][0], {0,0}});

    while(!pq.empty())
    {
        int dist = -pq.top().first; 
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();   

        if(dist > dis[r][c]) continue; 

        for(int t = 0 ; t < 4 ; t++)
        {
            int nr = r + dr[t];
            int nc = c + dc[t];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            
            int nextcost = A[nr][nc];
            
            if(dis[nr][nc] > dis[r][c] + nextcost)
            {
                dis[nr][nc] = dis[r][c] + nextcost;
                pq.push({-dis[nr][nc], {nr,nc}});
            }
        }
    }

    return dis[N-1][N-1];
}

int main()
{
    int T = 1;
    while(true)
    {
        cin >> N; if(N == 0) break;
        
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                cin >> A[i][j];
            }
        }
        
        int ans = di();

        cout << "Problem " << T << ": " << ans << '\n';

        T++;
    }
}