#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define pp pop_back
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define pll pair<ll, ll>

typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define weight first
#define vertex second
#define all(v) v.begin(), v.end()
using namespace std;

int SOURCE = 0, SINK = 25;

int c[52][52];
int f[52][52];
int level[52];
int work[52];
vector<int> graph[52];

//make levelGraph
bool bfs()
{
    //레벨 그래프 초기화
    fill(level, level + 52, -1);
    queue<int> q;
    q.push(SOURCE);
    level[SOURCE] = 0;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        FORE(next, graph[now])
        {
            //레벨이 아직 정해지지 않았고 잔여 용량이 존재하는 노드에 대해서
            if(level[next] == -1 && c[now][next] - f[now][next]>0) 
            {
                q.push(next);
                level[next] = level[now] + 1;
            }
        }
    }
    //싱크의 레벨이 할당이 되었는지의 여부
    return level[SINK] != -1;
}

// 소스 -> 싱크로 유량을 흘려줄 때 레벨 그래프에서의 차이가 딱 1만큼 클때만 유량을 흘려줄 수 있다.
int dfs(int x, int flow)
{
    if(x == SINK) return flow;

    //레벨 차이가 딱 1차이나는 정점으로만 유량을 흘려보낸다.
    for(int& i = work[x]; i < graph[x].size() ; i++)
    {
        int next = graph[x][i];
        if(level[next] == level[x]+1 && c[x][next] - f[x][next] > 0)
        {
            int ret = dfs(next, min(flow, c[x][next] - f[x][next]));
            if(ret)
            {
                //정방향 유량
                f[x][next] += ret;
                //역방향 유량
                f[next][x] -= ret;
                return ret;
            }
        }
    }
    return 0;
}

int charToInteger(char a)
{
    if(a <= 'Z') return (int)(a-'A');
    return (int)(a-'a'+26);
}

int main()
{
    fio();
    int N; cin>>N;

    // A~Z를 정수 0~25으로, a~z를 26~51로 설정
    FOR(i,N,0)
    {
        char start, end; 
        int cost; 

        cin>>start>>end>>cost;

        int s = charToInteger(start);
        int e = charToInteger(end);

        //양방향
        graph[s].push_back(e);
        graph[e].push_back(s);

        c[s][e] += cost;
        c[e][s] += cost;
    }

    //레벨 그래프가 생성되는 경우에만 동작함
    int ans = 0;
    while (bfs())
    {
        fill(work, work + 52, 0);
        while (true)
        {        
            int flow = dfs(SOURCE, INT_MAX);
            if(!flow) break;
            ans += flow;
        }
    }
    cout<<ans;   
}