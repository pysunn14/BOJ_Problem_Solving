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

int N;
int d[31];
void solve()
{
    d[2] = 3;

    for(int i = 4 ; i <= N ; i += 2)
    {
        d[i] = 3*d[i-2] + 2; 
        for(int j = i-4 ; j >= 2; j -= 2) d[i] += d[j]*2;
    }
    cout<<d[N];
}

int main()
{
    fio();
    cin>>N;
    solve();
}