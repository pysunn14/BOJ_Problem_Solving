#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define test(a) \
    int _;      \
    cin >> _;   \
    FOR(a, _, 0)
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
#define mid (lo + hi) / 2
using namespace std;

bool vis[501];
bool finished[501];
vector<int> graph[501];

void init()
{
    FOR(i, 501, 0)
    {
        vis[i] = 0;
        finished[i] = 0;
        graph[i].clear();
    }
}

bool cycle = false;
void dfs(int now)
{
    vis[now] = true;

    FORE(next, graph[now])
    {
        if(vis[next] && finished[next])
        {
            cycle = true;
        }

        if (!vis[next])
        {
            dfs(next);
        }
    }
    finished[now] = true;   
}

int test_case = 1;
int main()
{
    fio();

    while(true)
    {
        init();
        int n, m;
        cin >> n >> m;
        if (!n && !m) return 0;

        FOR(i, m, 0)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        // dfs
        int tree_count = 0;
        FOR(i, n + 1, 1)
        {
            if (!vis[i]) 
            {
                dfs(i);
                //만약 사이클이 존재하는 경우라면 트리에 포함하지 않음.
                if(!cycle )tree_count++;
                cycle = false;
            }
        }

        cout << "Case " << test_case << ": ";

        switch (tree_count)
        {
        case 0:
            cout << "No trees.\n";
            break;

        case 1:
            cout << "There is one tree.\n";
            break;

        default:
            cout << "A forest of " << tree_count << " trees.\n";
            break;
        }
        test_case++;
    }
}