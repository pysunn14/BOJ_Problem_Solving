#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define test(a) int _; cin >> _; FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define weight first
#define vertex second
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

int main()
{
    fio();

    int N,M;
    cin>>N>>M;

    int A[601][601];

    int r,c;
    FOR(i,N,0)
    {
        string s; cin>>s;
        FOR(j,M,0)
        {
            A[i][j] = s[j];
            if(s[j] == 'I')
            {
                r = i;
                c = j;
            }
        }
    }

    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};

    int ans = 0;
    bool vis[601][601] = {0};
    queue<pii> q;
    q.push({r,c});
    vis[r][c] = true;

    while (!q.empty())
    {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        if(A[cr][cc] == 'P') ans++;

        FOR(t,4,0)
        {
            int nr = cr + dr[t];
            int nc = cc + dc[t];

            if(nr >= 0 && nc >= 0 && nr < N && nc < M && !vis[nr][nc] && A[nr][nc] != 'X')
            {
                q.push({nr,nc});
                vis[nr][nc] = true;
            }
        }
    }
    

    if(!ans) cout<<"TT";
    else cout<<ans;
}