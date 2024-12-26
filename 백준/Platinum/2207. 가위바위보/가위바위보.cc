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

int N,M; 
const int SIZE = 10000;

vector<int> graph[2 * SIZE + 1];
vector<int> rgraph[2 * SIZE + 1];
vector<int> order;

bool vis[2 * SIZE + 1];
int SCC[2 * SIZE + 1];
int SCC_IDX;

//가위는 1~10000 까지. 주먹은 10001~20000까지.
void dfs(int n)
{
    vis[n] = true;
    FORE(next, graph[n]) if(!vis[next]) dfs(next);
    order.push_back(n);
}

void rdfs(int n)
{
    vis[n] = true;
    FORE(next, rgraph[n]) if(!vis[next]) rdfs(next);
    SCC[n] = SCC_IDX;
}

bool kosaraju()
{
    FOR(i,M+1,1) if(!vis[i]) dfs(i);
    FOR(i,SIZE + M + 1, SIZE + 1) if(!vis[i]) dfs(i);

    fill(vis, vis + 2*SIZE+1, 0);

    reverse(all(order));

    //역방향 dfs
    FORE(i, order)
    {
        if(!vis[i])
        {
            // SCC그룹 설정
            rdfs(i);
            SCC_IDX++;
        }
    }

    // SCC 간섭 체크
    FOR(i,M+1,1) if(SCC[i] == SCC[i + SIZE]) return false;
    return true;
}

int main()
{
    fio();
    cin >> N >> M;

    //clauses 
    FOR(i,N,0)
    {
        int x,y; 
        cin >> x >> y;

        int X,Y;

        // 간선 1.

        // x가 불값 0이라면
        if(x > 0) X = x + SIZE;
        else X = -x;

        // y는 불값 1이어야한다.
        if(y > 0) Y = y;
        else Y = -y + SIZE;

        // x가 불값 0이라면 y는 불값 1이어야 한다.
        graph[X].push_back(Y);
        rgraph[Y].push_back(X);

        // 간선 2.

        // y가 불값 0이라면
        if(y > 0) Y = y + SIZE;
        else Y = -y;

        // x는 불값 1이어야한다.
        if(x > 0) X = x;
        else X = -x + SIZE;

        // y가 불값 0이라면 x는 불값 1이어야 한다.
        graph[Y].push_back(X);
        rgraph[X].push_back(Y);
    }

    if(kosaraju()) cout << "^_^";
    else cout << "OTL";
}