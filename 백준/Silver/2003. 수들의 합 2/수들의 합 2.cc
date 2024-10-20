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

int A[10001], S[10001];
int main()
{
    fio();

    int n,m; cin >> n >> m;
    int cnt = 0;
    FOR(i,n+1,1) cin >>A[i];
    S[1] = A[1];
    FOR(i,n+2,2) S[i] = S[i-1] + A[i];

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for(int j = i ; j <= n ; j++)
        {
            if(S[j] - S[i-1] == m) cnt++;
        }
    }

    cout << cnt;
}