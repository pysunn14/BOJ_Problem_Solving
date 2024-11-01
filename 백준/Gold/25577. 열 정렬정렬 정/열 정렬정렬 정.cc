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

map<int,int> m;

pii A[101010];
pii B[101010];
int G[101010];
bool vis[101010];
ll cnt;

void dfs(int now)
{
    vis[now] = true;
    if(!vis[G[now]]) 
    {
        cnt++;
        dfs(G[now]);
    }
}

int main()
{
    fio();

    int N; cin >> N;

    FOR(i,N+1,1) 
    {
        int x; cin >> x;
        A[i] = B[i] = {x, i};
    }

    sort(B + 1, B + N + 1);

    FOR(i,N+1,1)
    {
        G[i] = B[i].second;
    }

    FOR(i,N+1,1) if(!vis[i]) dfs(i);
    cout << cnt; 
}