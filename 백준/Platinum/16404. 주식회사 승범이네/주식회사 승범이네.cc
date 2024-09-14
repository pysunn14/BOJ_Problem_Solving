#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define test(a) int _; cin >> _; FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define weight first
#define vertex second
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

const int sz = 1010101;
ll A[sz];
ll tree[sz * 4];
ll lazy[sz * 4];

ll f(ll a, ll b)
{
    return a + b;
}

ll init(int lo, int hi, int node)
{
    if (lo == hi) return tree[node] = A[lo];
    return tree[node] = f(init(lo, mid, node * 2), init(mid + 1, hi, node * 2 + 1));
}

void lazy_update(int lo, int hi, int node)
{
    if(lazy[node])
    {
        tree[node] += (hi - lo + 1) * lazy[node];

        if(lo != hi)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll query(int lo, int hi, int node, int left, int right)
{
    lazy_update(lo, hi, node);
    if (left > hi || right < lo) return 0;
    if (left <= lo && hi <= right) return tree[node];
    return f(query(lo, mid, node * 2, left, right), query(mid + 1, hi, node * 2 + 1, left, right));
}

void update(int lo, int hi, int node, int left, int right, ll diff)
{
    lazy_update(lo, hi, node);

    if (left > hi || right < lo) return;
    if(left <= lo && hi <= right)
    {
        tree[node] += (hi - lo + 1) * diff;
        if(lo != hi)
        {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    update(lo, mid, node * 2, left, right, diff);
    update(mid + 1, hi, node * 2 + 1, left, right, diff);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
}

vector<int> graph[101010];
bool visited[101010];

//경로의 시작과 끝 점
int NODE[101010];
int S[101010];
int E[101010];

int cur = 0;
void dfs(int now)
{
    visited[now] = true;
    NODE[now] = ++cur;  

    //해당 노드의 dfs 시작
    S[now] = cur;

    FORE(next, graph[now])
    {
        if(!visited[next]) dfs(next);
    }

    //해당 노드의 dfs 끝
    E[now] = cur;
}

int main()
{
    fio();

    int N,M; cin>>N>>M;

    init(1,N,1);

    FOR(i,N+1,1) 
    {
        int x;
        cin>>x;
        graph[x].push_back(i);
    }
    dfs(1);

    FOR(i,M,0)
    {
        int t; 
        cin>>t;

        if(t == 1)
        {
            ll i,w; cin>>i>>w;
            update(1,N,1,S[i],E[i],w);
        }

        else
        {
            int i;
            cin>>i;
            cout <<query(1,N,1,NODE[i],NODE[i]) <<'\n';
        }
    }
}   