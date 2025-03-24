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

ll T[101010], D[101];
ll ans;

typedef struct 
{
    double T;
    double D;
}cow;

int main()
{
    fio();

    int N; cin >> N;

    vector<cow> v;
    FOR(i,N,0)
    {
        double T, D; cin >> T >> D;
        v.push_back({T,D});
    }

    sort(all(v), [](cow a, cow b){
        return a.D/a.T > b.D/b.T;
    });

    ll S[101010] = {0};

    S[0] = v[0].D;

    for(int i = 1 ; i < N ; i++) S[i] = S[i-1] + v[i].D;
    
    for(int i = 0 ; i < N ; i++) ans += (S[N-1] - S[i]) * v[i].T * 2LL;
    
    cout << ans;
}