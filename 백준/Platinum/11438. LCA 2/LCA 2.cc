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

int st[21][101010];

vector<int> graph[101010];

int depth[101010];
int parent[101010];
int table[18][101010];
int N; 

void dfs(int n)
{
    FORE(next, graph[n])
    {
        if(!depth[next])
        {
            //부모 노드 지정
            parent[next] = n;
            depth[next] = depth[n] + 1;
            dfs(next);
        }
    }
}

void make_sparse_table()
{
    for(int i = 1 ; i <= N; i++) table[0][i] = parent[i];
    for(int k = 1 ; k <= 17 ; k++) for(int i = 1 ; i <= N ; i++) table[k][i] = table[k-1][table[k-1][i]];
}

void make_tree()
{
    parent[1] = 1;
    depth[1] = 1;
    dfs(1);
}

// x와 y의 공통 조상 출력
int LCA(int x, int y)
{
    int n = abs(depth[x]-depth[y]);

    // 1. 깊이 맞추기
    int a, b;
    // 두 노드의 깊이가 같아질때까지 거슬러 올라간다
    if(depth[x] >= depth[y]){a = x; b = y;}
    else{a = y;b = x;}

    for(int i = 17 ; i >= 0; i--)
    {
        if(n >= (1<<i))
        {
            n -= (1<<i);
            a = table[i][a];
        }
    }

    // 2. 조상 맞추기
    if(a == b) return a;


    // 조상을 구해가며 같은지 확인하기
    for(int i = 17 ; i >= 0; i--)
    {
        if(!table[i][a] && a != 1) continue;
        if(table[i][a] != table[i][b]) 
        {
            a = table[i][a];
            b = table[i][b];
        }
    }
    return table[0][a];
}

int main()
{
    fio();

    cin >> N;
    FOR(i,N-1,0)
    {
        int x,y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    make_tree();
    make_sparse_table();

    int M; cin >> M;
    while(M--)
    {
        int x,y; 
        cin >> x >> y;
        cout << LCA(x,y) << '\n';
    }
}