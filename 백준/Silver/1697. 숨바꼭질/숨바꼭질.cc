#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define pp pop_back
#define ub upper_bound
#define lb lower_bound
#define pii pair<int,int>
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define weight first 
#define vertex second
using namespace std;

int main()
{
    fio();
    int n,k; cin>>n>>k;
    vector<pii> t;
    bool vis[333333] = {0};
    int dis[333333];
    fill(dis,dis+333333, INT_MAX);

    queue<int> q; 
    q.push(n);
    dis[n] = 0;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        // 도착한 경우
        if (k == now) break;
        else // 아직 안도착한 경우
        {
            if ((now - 1 >= 0) && (dis[now - 1] > dis[now] + 1))
            {
                q.push(now - 1);
                // cout<<dis[now-1]<<endl;
                dis[now - 1] = dis[now] + 1;
                // cout << now << " : 감소시킵니다 -> " << now-1 << " 의 시간을 : " <<dis[now-1] <<endl;
            }

            if ((now + 1 <= k) && (dis[now + 1] > dis[now] + 1))
            {
                q.push(now + 1);
                dis[now + 1] = dis[now] + 1;
            }
            if ((2 * now <= 2 * k) && (dis[2 * now] > dis[now] + 1))
            {
                q.push(2 * now);
                dis[2 * now] = dis[now] + 1;
            }
        }
    }
    cout << dis[k];
}