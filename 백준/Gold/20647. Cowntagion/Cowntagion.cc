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

bool vis[101010];
vector<int> graph[101010];
vector<int> tree[101010];

ll ans = 0;

void make_tree(int n)
{
    vis[n] = true;
    FORE(child, graph[n])
    {
        if(vis[child]) continue;

        tree[n].push_back(child);
        make_tree(child);
    }
}

void go(int n)
{
    // terminal
    if(tree[n].empty()) return;

    // 자식 노드 개수 만큼 만들기 
    ans += ceil(log2(tree[n].size()+1));
    
    // 자식 노드 개수만큼 전파하기 
    ans += tree[n].size();

    // 부모 노드 제외 전이 
    FORE(child, tree[n]) go(child);
}

int main()
{
    fio();

    int N; 
    cin >> N;

    FOR(i,N-1,0)
    {
        int a, b;

        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    make_tree(1);

    go(1);
    
    cout << ans;
}