#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define pp pop_back
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define test(a) \
    int _;      \
    cin >> _;   \
    FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define weight first
#define vertex second
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

int A[1025][1025];
int S[1025][1025];

int main()
{
    fio();
    int N,M;
    cin>>N>>M; 

    FOR(i,N,0) FOR(j,N,0) cin>>A[i+1][j+1];

    //prefix sum
    FOR(i,N+1,1) 
    {
        FOR(j,N+1,1) 
        {
            if(j == 1) S[i][1] = A[i][1];
            else S[i][j] = S[i][j-1] + A[i][j]; 
        }
    }

    //query
    FOR(i,M,0)
    {
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;

        int sum = 0;

        FOR(r,r2+1,r1)
        {
            sum += S[r][c2]-S[r][c1-1];    
        }

        cout<<sum<<'\n';
    }
} 