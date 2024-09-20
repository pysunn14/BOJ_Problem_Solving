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

vector<bool> graph[5000];

int main()
{
    fio();
    int n; 
    cin>>n;

    FOR(i,n,0) 
    FOR(j,n,0) 
    {
        char x; cin>>x;
        // j가 i보다 크면 입력 안받음
        if(i > j)
        {
            if(x == '+') graph[i].push_back(1);
            else graph[i].push_back(0);
        }
    }

    int m; cin>>m;
    FOR(i,m,0)
    {
        int b, c, d;
        cin>>b>>c;

        if(c > b)
        {
            d = c;
            c = b;
            b = d;
        }

        if(graph[b][c]) cout << '+' << '\n';
        else cout << '-' << '\n';
    }
}