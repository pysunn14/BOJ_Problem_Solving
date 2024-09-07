#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define test(a) int _; cin >> _; FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define weight first
#define vertex second
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

const int mod = 1000;
ll N, M;

array<array<ll,5>,5> mul(array<array<ll,5>,5> A, array<array<ll,5>,5> B)
{
    array<array<ll, 5>,5> C;
    FOR(i, N, 0)
    {
        FOR(j, N, 0)
        {
            ll sum = 0;
            FOR(k, N, 0) sum += A[i][k] * B[k][j];
            // sum = (sum % mod + ((A[i][k] % mod) * (B[k][j] % mod)) % mod) % mod;
            C[i][j] = sum % 1000;
        }
    }
    return C;
}

array<array<ll,5>,5> dnq(array<array<ll,5>,5> A, ll n)
{
    if(n == 1) return A;
    if(n % 2 == 0) 
    {
        array<array<ll, 5>,5> T = dnq(A, n/2);
        return mul(T,T);
    }
    if(n % 2 == 1) return mul(dnq(A, n-1), A);
}

int main()
{
    fio();  
    cin>>N>>M;
    array<array<ll, 5>,5> A;
    array<array<ll, 5>,5> R;

    FOR(i,N,0) FOR(j,N,0) cin>>A[i][j];

    R = dnq(A, M);

    FOR(i, N, 0)
    {
        FOR(j, N, 0)
        cout << R[i][j] % mod << ' ';
        cout << '\n';
    }
}