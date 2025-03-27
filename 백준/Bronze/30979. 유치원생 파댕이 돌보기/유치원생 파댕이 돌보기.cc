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

    int T; cin >> T;

    int N; cin >> N;

    ll F[111];
    FOR(i,N+1,1) cin >> F[i]; 

    if(accumulate(F+1, F+1+N, 0) >= T) cout << "Padaeng_i Happy";
    else cout << "Padaeng_i Cry"; 
}