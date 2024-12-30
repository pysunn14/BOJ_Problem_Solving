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

ll M;
int com[2020][2020];

void comb()
{
    FOR(i,2001,0) com[i][i] = com[i][0] = 1;
    FOR(i,2001,2) FOR(j,i,1) com[i][j] = (com[i-1][j-1] + com[i-1][j]) % M;
}

vector<int> lucas(ll val)
{
    vector<int> ret;
    while (val > 0)
    {
        ret.push_back(val % M);
        val /= M;
    }
    return ret;
}

int main()
{
    fio();

    ll N,K; 
    cin >> N >> K >> M;
    comb(); 

    vector<int> lN = lucas(N);
    vector<int> lK = lucas(K);
    
    ll ans = 1;
    for(int i = 0 ; i < min(lN.size(), lK.size()); i++)
    {
        int n = lN[i];
        int k = lK[i];
        
        if(n < k) 
        {
            ans = 0;
            break;
        }

        ans *= com[n][k];
        ans %= M;
    }
    cout << ans;
}