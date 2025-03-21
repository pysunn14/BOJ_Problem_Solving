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

char color[101010];

int parent[101010];

bool vis[101010];
vector<int> graph[101010];

int find(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if(a!=b)
    {
        if(a < b) parent[b] = a;
        else parent[a] = b;
    }
}

void dfs(int n)
{
    vis[n] = true;
    FORE(next, graph[n])
    {
        // 동일하다면? 
        if(!vis[next] && color[next] == color[n])
        {
            merge(n, next);
            dfs(next);
        }
    }
}
int main()
{
    fio();

    int N, M; cin >> N >> M;

    FOR(i,101010,0) parent[i] = i;

    string s; cin >> s;
    FOR(i,s.size(),0) color[i+1] = s[i];

    FOR(i,N-1,0)
    {
        int X,Y; 
        cin >> X >> Y;
        graph[X].push_back(Y);
        graph[Y].push_back(X);
    }

    FOR(i,N+1,1) if(!vis[i]) dfs(i);

    while(M--)
    {
        int A, B; cin >> A >> B;
        char C; 
        cin >> C;
        
        bool ok = true;

        // A에서 B로 가는 농장 경로 상에 C가 존재하는지??
        if(find(A) == find(B))
        {
            // A와 C 종류값이 같아야 함.
            if(color[A] != C) ok = false;
        }
        
        cout << ok;
    }
}