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

int nxt[101010];
int indegree[101010]; 

vector<int> ans;
vector<pii> v;

void dfs(int n)
{
    ans.push_back(n);

    if(nxt[n])
    {
        int nx = nxt[n];
        nxt[n] = 0;
        dfs(nx);
    }
}

int main()
{
    fio();

    int N; cin >> N;
    ll A[101010];
    FOR(i,N+1,1) 
    {
        cin >> A[i];
        nxt[i] = A[i]; 
        indegree[A[i]]++; 
    }
    
    // indegree가 적은 순으로 sort하여 dfs() 
    FOR(i,N+1,1)
    {
        v.push_back({indegree[i], i});
    }

    sort(all(v));

    dfs(1);
    for(auto[d, i] : v) 
    {
        if(nxt[i])
        {
            dfs(i);
        }
    }

    cout << ans.size() - 1 << '\n'; 
    FOR(i, ans.size(), 1) cout << ans[i] << ' ';
}