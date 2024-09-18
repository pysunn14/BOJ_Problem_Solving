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

int d[101][101010];
int W[101], V[101];

int main()
{
    fio();

    int N, K; cin>>N>>K;
    FOR(i,N+1,1) cin>>W[i]>>V[i];

    FOR(i,N+1,1)
    {
        FOR(j,K+1,1) 
        {
            d[i][j] = d[i-1][j];
            if(j >= W[i]) d[i][j] = max(d[i][j], d[i-1][j - W[i]] + V[i]); 
        }
    }
    cout << d[N][K];
}