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

int main()
{
    fio();

    test(T)
    {
        int n,m; cin >> n >> m;
        double S[1010] = {0}, A[1010] = {0};
        double W[1010] = {0};

        FOR(i,m,0)
        {
            int a,b,p,q; 
            cin >> a >> b >> p >> q;

            S[a] += p;
            A[a] += q;

            S[b] += q;
            A[b] += p;
        }

        FOR(i,n+1,1) 
        {
            if(S[i] + A[i] == 0) W[i] = 0;
            else W[i] = S[i]*S[i] / (S[i] * S[i] + A[i]*A[i]);
        }

        double max_e = *max_element(W+1,W+1+n);
        double min_e = *min_element(W+1,W+1+n);

        cout << (ll)(1000*max_e) << '\n' << (ll)(1000*min_e) << '\n';
    }
}