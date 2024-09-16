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

bool vis[1001];
vector<int> graph[1001];
int path[1001];

void bfs(int S)
{
    queue<int> q;
    q.push(S);
    vis[S] = true;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        FORE(next, graph[now])
        {
            if(vis[next]) continue;
            q.push(next);
            vis[next] = true;
            path[next] = now;
        }
    }
}

vector<string> bit;
int N,K; 

void bitComparison(int a, int b)
{
    // 비트가 다른 개수
    int cnt = 0;

    FOR(i,K,0)
    {
        if(bit[a][i] != bit[b][i]) cnt++;
    }

    if(cnt == 1)
    {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

int main()
{
    fio();

    cin >> N >> K;

    bit.push_back("");
    FOR(i,N,0)
    {
        string s; cin >> s;
        bit.push_back(s);
    }

    int S,E; cin >> S >> E;

    FOR(i,N+1,1)
    {
        FOR(j,N+1,1)
        {
            if(i == j) continue;
            bitComparison(i, j);
        }
    }

    bfs(S);
    if(vis[E])
    {
        vector<int> ans;

        int now = E;

        while(now != S)
        {
            ans.push_back(now);
            now = path[now];
        }
        ans.push_back(S);
        reverse(all(ans));
        FORE(a, ans) cout << a << ' ';
    }
    else cout << -1;
}