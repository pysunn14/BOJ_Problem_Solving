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

    int A[1010101];

    int res[1010101];

    FOR(i,N+1,1) 
    {
        res[i] = -1;
        cin >> A[i];
    }
    stack<pii> s;

    s.push({A[1], 1});

    FOR(i,N+1,2)
    {
        if(A[i] <= s.top().first) s.push({A[i], i});

        else 
        {
            while (!s.empty() && A[i] > s.top().first)
            {
                res[s.top().second] = A[i];
                s.pop();
            }
            s.push({A[i],i});
        }
    }

    FOR(i,N+1,1) cout << res[i] << ' ';
}