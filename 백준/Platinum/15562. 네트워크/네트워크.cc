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

priority_queue<int> graph[1010101];

ll networks = 0;
void sub_dfs(int now)
{
    if(graph[now].empty()) 
    {
        networks++;
        return;
    }

    while(true) 
    {
        if(graph[now].empty()) break;
        int next = -graph[now].top();
        graph[now].pop();
        now = next;
    }
    networks++;
}

void dfs(int now)
{
    if(graph[now].empty()) return;
    while(!graph[now].empty())
    {
        int next = -graph[now].top();
        graph[now].pop();
        sub_dfs(next);
    }
}

int main()
{
    fio();
    int N,M; cin >> N >> M;
    FOR(i,M,0)
    {
        int A,B; cin >> A >> B;
        graph[A].push(-B);
    }
    FOR(i,N+1,1) dfs(i);
    cout << networks;
}

