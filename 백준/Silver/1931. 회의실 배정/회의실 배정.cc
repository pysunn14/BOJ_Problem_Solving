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

#define s second
#define f first

int main()
{
    fio();

    int N; cin >> N;

    vector<pii> job(N,{0,0});
    FOR(i,N,0) cin >> job[i].s >> job[i].f;

    sort(all(job), [](pii j1, pii j2)
    {
        if(j1.f == j2.f) return j1.s < j2.s;
        return j1.f < j2.f;
    }
    ); 

    int now = 0;
    int cnt = 1;
    for(int i = 1 ; i < N ; i++)
    {
        if(job[i].s >= job[now].f)
        {
            cnt++;
            now = i;
        }
    }

    cout << cnt;
}