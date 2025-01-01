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

int m; 
int f[202020];
// sparse table
int st[21][202020];

void make_sparse_table()
{
    // 1번 이동해서 도착하는 정점
    for(int i = 1 ; i <= m ; i++) st[0][i] = f[i];

    // log N번 이동해서 도착하는 정점
    for(int k = 1 ; k <= 20; k++) for(int i = 1 ; i <= m; i++) st[k][i] = st[k-1][st[k-1][i]];
}

int query(int n, int x)
{
    // x 정점에서 출발해서 n개의 간선을 이동해 도착한 정점 찾기
    for(int i = 20 ; i >= 0; i--)
    {
        if(n < 0) break;
        // 포함된 2^k 만큼 생각해서 이동
        if(n >= (1 << i))
        {
            n -= (1 << i);
            x = st[i][x];
        }
    }
    return x;
}

int main()
{
    fio();

    cin >> m; FOR(i,m+1,1) cin >> f[i];
    make_sparse_table();

    int Q; cin >> Q;
    while (Q--)
    {
        int n,x; cin >> n >> x;
        cout << query(n,x) << '\n';
    }
}