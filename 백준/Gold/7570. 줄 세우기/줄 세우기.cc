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

bool vis[1010101];
int c[1010101];
ll A[1010101];

int main()
{
    fio();

    int N; cin >> N;

    int mx = 1;
    FOR(i,N+1,1) cin >> A[i];

    if(N == 1)
    {
        cout << 0;
        return 0;
    }

    // 1씩 증가하는 LIS의 길이 
    FOR(i,N+1,1) 
    {
        if(!vis[A[i] - 1])
        {
            vis[A[i]] = true;
            c[A[i]] = 1;
        }

        else 
        {
            vis[A[i]] = true;
            c[A[i]] = c[A[i] - 1] + 1;
            mx = max(mx, c[A[i]]);
        }
    }

    cout << N - mx;
}