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

    while(true)
    {
        int N; cin>>N;
        if(cin.eof()) break;
        int A[101010]; FOR(i,N+1,1) cin>>A[i];
        vector<int> lis;

        lis.push_back(A[1]);
        FOR(i,N+1,2)
        {
            if(lis.back() < A[i]) lis.push_back(A[i]);
            else
            {
                auto it = lower_bound(all(lis), A[i]);
                *it = A[i];
            }
        }

        cout<<lis.size()<<'\n';
    }
}