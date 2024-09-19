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

int k[5050][5050];
int P[5050][5050];
int S[5050][5050];

int prefix_sum(int r1, int c1, int r2, int c2)
{
    return S[r2][c2] - S[r1-1][c2] - S[r2][c1-1] + S[r1-1][c1-1];
}

int main()
{
    fio();
    int N; cin>>N;
    FOR(i,N+1,1) FOR(j,N+1,1) cin>>k[i][j];

    //prefix_sum
    FOR(i,N+1,1)
    {
        //row
        P[i][1] = k[i][1];
        FOR(j,N+1,2) P[i][j] = P[i][j-1] + k[i][j];
    }

    //col
    FOR(i,N+1,1)
    {
        S[1][i] = P[1][i];
        FOR(j,N+1,2) S[j][i] = S[j-1][i] + P[j][i];
    }

    int Q; cin>>Q;
    FOR(i,Q,0) // 십만
    {
        int r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;
        
        //solve : 구간에서 가장 바깥쪽 k값은 빼지고, 안의 k값은 더해진다.
        int inner = prefix_sum(r1+1,c1+1,r2-1,c2-1);
        int outer = prefix_sum(r1,c1,r2,c2);

        cout << inner * 2 - outer <<'\n';
    }
}