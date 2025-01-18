#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define test(a) int _; cin >> _; FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

vector<int> graph[501];
ll res[501];
ll t[501];

int indegree[501];
int N; 

void toyopo()
{
    queue<int> q;
    FOR(i,N+1,1) 
    {
        if(!indegree[i]) 
        {
            q.push(i);
            res[i] = t[i];
        }
    }
    
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        
        FORE(next, graph[now])
        {
            --indegree[next];
            res[next] = max(res[next], res[now] + t[next]);
            if(!indegree[next]) q.push(next);
        }
    }
}

int main()
{
    fio();
    
    cin >> N;    
    FOR(i, N+1, 1)
    {
        cin >> t[i];
        while (true)
        {
            int x; cin >> x;
            if(x == -1) break; 
            graph[x].push_back(i);
            indegree[i]++;
        }
    }
    
    toyopo();
    
    FOR(i,N+1,1) cout << res[i] << '\n';
}