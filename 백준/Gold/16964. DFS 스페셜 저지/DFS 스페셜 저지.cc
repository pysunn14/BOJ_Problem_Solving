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

set<int> graph[101010];

ll cnt = 0;
vector<int> seq;
int N; 

void dfs()
{
    stack<int> stk;
    stk.push(1);
    cnt++;

    while (!stk.empty())
    {
        int now = stk.top();
        // 1. DFS의 다음 간선이 존재하고, 갈 수 있다.
        // 2. DFS에서 더 이상 갈 곳이 없는 경우일 수가 있다.
        int next = seq[cnt];

        // cout << now << ' ' << next << '\n';

        // next가 다음 간선 집합에 존재하는 경우
        if(graph[now].find(next) != graph[now].end())
        {
            //cout << "connect\n";
            stk.push(next);
            graph[now].erase(next);
            graph[next].erase(now);
            cnt++;

            if(cnt == N-1)
            {
                cout << 1;
                exit(0);
            }
        }

        // next가 다음 간선 집합에 존재하지 않는 경우
        else
        {
            // 그런데 아직 가야할 간선이 남아있는 경우
            if(!graph[now].empty())
            {
                cout << 0;
                exit(0);
            }
            stk.pop();
        }
    }
}

int main()
{
    fio();

    cin >> N;

    FOR(i,N-1,0)
    {
        int x,y; 
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }

    FOR(i,N,0) 
    {
        int x; cin >> x;
        seq.push_back(x);
    }

    if(seq[0] != 1) 
    {
        cout << 0;
        return 0;
    }

    dfs();
    // start


    if(cnt == N-1) cout << 1;
    else cout << 0;
}