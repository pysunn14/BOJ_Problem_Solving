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

int A[101010];

vector<vector<int>> tree;

int main()
{
    fio();

    int N; cin >> N;

    FOR(i,N+1,1) cin >> A[i]; 

    FOR(i,N+1,2)
    {
        if(A[i] > A[i-1])
        {
            cout << -1;
            return 0;
        }
    }

    if (A[N] > 2)
    {
        cout << -1;
        return 0;
    }

    FOR(i,N,1)
    {
        if(A[i] == 1)
        {
            cout << -1;
            return 0;
        }
    }
    
    ll ans = 0;
    int num = 1;
    for(int i = N ; i >= 1; i--)
    {
        vector<int> layer;
        
        FOR(j,A[i],0) layer.push_back(num++);
        tree.push_back(layer);
        ans += A[i];
    }

    // 트리를 출력한다.
    cout << ans << '\n';

    if(tree[0].size() == 2) cout << tree[0][0] << ' ' << tree[0][1] << '\n';

    FOR(i,tree.size(),1)
    {
        FOR(j, tree[i].size(), 0)
        {
            if(j >= tree[i-1].size()) cout << tree[i][j] << ' ' << tree[i-1][tree[i-1].size()-1] << '\n';
            else cout << tree[i][j] << ' ' << tree[i-1][j] << '\n';
        }
    }
}