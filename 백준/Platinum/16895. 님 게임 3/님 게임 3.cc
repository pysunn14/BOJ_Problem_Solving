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

int P[1010];
ll XOR;
ll ans;

int main()
{
    fio();

    int N; 
    cin >> N;

    FOR(i,N+1,1) cin >> P[i];
    FOR(i,N+1,1) XOR ^= P[i];

    FOR(i,N+1,1)
    {
        FOR(j,P[i],0)
        {
            if(!(XOR ^ P[i] ^ j)) ans++;
        }
    }

    cout << ans;
}