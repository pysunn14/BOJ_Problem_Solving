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

int main()
{
    fio();

    int N; cin >> N;

    ll A[1010];
    
    FOR(i,N+1,1) cin >> A[i];
    
    sort(A+1, A+N+1);

    ll M = A[1]; //만들수 있는 최대의 수임

    if(M > 1)
    {
        cout << 1;
        exit(0);
    }

    FOR(i, N+1, 2)
    {
        ll need = M + 1;

        if(A[i] <= need && need <= A[i] + M)
        {
            M = max(M, M + A[i]);
        }

        else 
        {
            cout << M + 1;
            exit(0);
        }
    }
    
    cout << M + 1; 
}