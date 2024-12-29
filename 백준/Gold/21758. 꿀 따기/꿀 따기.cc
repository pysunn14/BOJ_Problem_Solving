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

int S[101010];
int A[101010];

int main()
{
    fio();

    int N; cin >> N;

    FOR(i,N+1,1) cin >> A[i];

    S[1] = A[1]; FOR(i,N+1,2) S[i] = S[i-1] + A[i];

    int ans = 0;

    FOR(i,N,2) 
    {
        ans = max(ans, S[N] - S[1] + (S[N] - S[i]) - A[i]);
        ans = max(ans, (S[N-1]) + (S[i-1]) - A[i]);
        ans = max(ans, S[i]-S[1] + S[N-1]-S[i-1]);
    }
    cout << ans;
}