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

int cnt[202020];
int main()
{
    fio();

    int N,M; 
    cin >> N >> M;

    while(N--)
    {
        int k; cin >> k;
        
        vector<int> endpoint;
        
        FOR(i,k+1,1)
        {
            int p; cin >> p;
            if(i == 1 || i == k) cnt[p]++;
        }
    }    

    ll sum = 0;
    FOR(i,M+1,1) sum += cnt[i];

    ll now = 0;
    FOR(i,M+1,1)
    {
        now += cnt[i];

        if(now * 2 >= sum)
        {
            cout << i;
            return 0;
        }
    }
}