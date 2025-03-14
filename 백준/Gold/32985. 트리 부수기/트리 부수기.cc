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

vector<int> graph[202020];
int ances[202020];

void go(int n)
{
    FORE(child, graph[n])
    {
        if(ances[child] > 0 || child == 0) continue; 
        ances[child] = ances[n] + 1;
        go(child);
    }
}

int main()
{
    fio();

    int N; cin >> N;

    FOR(i,N-1,0)
    {
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<char> s;

    go(0);

    FOR(i,N,1)
    {
        if(((N-1)-ances[i]) % 2 == 1) s.push_back('1');
        else s.push_back('0');
    }
    
    reverse(all(s));
    FORE(ss, s) cout << ss;
}