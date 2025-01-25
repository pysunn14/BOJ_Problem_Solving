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

bool vis[1010101];
vector<int> graph[1010101];
vector<int> tree[1010101];

void maketree(int n)
{
    vis[n] = true;
    FORE(child, graph[n])
    {
        if(!vis[child])
        {
            tree[n].push_back(child);
            maketree(child);                        
        }
    }
}

#define LEAF 1
#define EARLY 2

int ans;
int node[1010101];

int tree_dp(int n)
{
    // 만약 n노드는 리프노드라면 
    if(tree[n].empty()) return node[n] = LEAF;
    
    bool have_leaf_child = false;
    FORE(child, tree[n])
    {
        int response;
        if(!node[child])
        {
            response = tree_dp(child);
        }
        else response = node[child];

        if(response == LEAF) have_leaf_child = true;
    }

    // 자식 노드 중에 단 하나라도 리프노드가 있다면, n노드는 "얼리어답터"로 규정한다.
    if(have_leaf_child) 
    {
        ans++;
        return node[n] = EARLY;
    }
        
    return node[n] = LEAF;
}

int main()
{
    fio();

    int N; cin >> N;

    FOR(i,N-1,0)
    {
        int u,v; 
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    maketree(1);
    tree_dp(1);
    
    cout << ans;   
}