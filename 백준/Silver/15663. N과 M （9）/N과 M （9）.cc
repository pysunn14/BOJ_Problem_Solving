#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define test(a) int _; cin >> _; FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define weight first
#define vertex second
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

int main()
{
    fio();

    int N,M; cin>>N>>M;

    vector<int> v;
    FOR(i,N,0)
    {
        int x; cin>>x;
        v.push_back(x);
    }

    // N개의 자연수 중에서 M개를 고른 수열

    sort(all(v));
    vector<int> prev;
    do
    {
        vector<int> now;
        FOR(i,M,0) now.push_back(v[i]);
        if(now == prev) continue;
        prev = now;

        FORE(n, now) cout<<n<<' ';
        cout<<'\n';
        
    } while (next_permutation(all(v)));
    

    


}