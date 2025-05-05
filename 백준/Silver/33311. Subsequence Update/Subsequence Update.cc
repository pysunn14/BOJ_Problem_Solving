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

    test(t)
    {
        int n,l,r; cin >> n >> l >> r;

        int a[101010];

        vector<int> left;
        vector<int> right;
        
        FOR(i,n+1,1) cin >> a[i];

        ll ls = 0;
        ll rs = 0; 

        FOR(i,r+1,1) left.push_back(a[i]);
        sort(all(left));
        FOR(i,r-l+1,0) ls += left[i];

        FOR(i,n+1,l) right.push_back(a[i]);
        sort(all(right));
        FOR(i,r-l+1,0) rs += right[i];
        
        // 1. 1~r 중에 r-l+1개 작게 뽑아 더하기
        // 2. r ~ n 중에 작게뽑아 더하기 중에 최소

        cout << min(ls, rs) << '\n';
    }
}