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

typedef struct {
    int gold, silver, bronze, number;
}medal;

vector<medal> v;

int rk[1010101];

int main()
{
    fio();

    int N,K; cin >> N >> K;

    FOR(i,N,0)
    {
        int x; cin >> x;
        int g,s,b; cin >> g >> s >> b;
        v.push_back({g,s,b,x});
    }

    sort(all(v), [](medal a, medal b){

        if(a.gold == b.gold)
        {
            if(a.silver == b.silver) return a.bronze > b.bronze;
            return a.silver > b.silver;
        }
        return a.gold > b.gold;
    });

    int now = 1;
    FORE(vv, v) 
    {
        int num = vv.number;
        rk[num] = now++;
    }

    for(int i = 1 ; i <= N-1; i++)
    {
        if(v[i].gold == v[i-1].gold && v[i].silver == v[i-1].silver && v[i].bronze == v[i-1].bronze)
        {
            rk[v[i].number] = rk[v[i-1].number];
        }
    }

    cout << rk[K];
}