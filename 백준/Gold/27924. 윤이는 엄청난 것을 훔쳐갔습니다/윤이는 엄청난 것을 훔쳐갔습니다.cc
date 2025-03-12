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

int level[202020];
vector<int> graph[202020];

map<int, int> M[3];

void dfs(int n, int idx)
{
    // 리프노드인지 체크 : 사이즈가 1 인 경우 
    if(graph[n].size() == 1 && level[n] != 0)
    {
        M[idx][n] = level[n];
        return;
    }

    FORE(next, graph[n])
    {
        if(level[next] == -1)
        {
            level[next] = level[n] + 1;
            dfs(next, idx);
        }
    }
}

int main()
{
    fio();
    int N;
    cin >> N;

    FOR(i, N - 1, 0)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int pos[3]; FOR(i,3,0) cin >> pos[i];

    // 예외 처리 : 윤이가 최초에 리프노드에 있음
    if(graph[pos[0]].size() == 1)
    {
        cout << "YES\n";
        return 0;
    }

    FOR(i,3,0) 
    {
        FOR(i,202020,0) level[i] = -1;
        level[pos[i]] = 0;
        dfs(pos[i], i);
    }

    // 검사 : Y가 F,D보다 일찍 도달 가능한 리프가 존재함 
    FORE(m, M[0])
    {
        int node = m.first;
        int time = m.second;

        if(time < M[1][node] && time < M[2][node])
        {
            cout << "YES\n";
            return 0;
        }
    }
    
    cout << "NO\n";
}