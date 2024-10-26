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
    
    int n; 
    cin >> n;
    vector<int> A(n,0);

    FOR(i,n,0) cin >> A[i];
    sort(all(A));

    ll ans = 0;

    // 하나를 설정함
    FOR(i,n,0)
    {
        vector<int> v;
        FOR(j,n,0)
        {
            if(i == j) continue;
            v.push_back(A[j]);
        }

        // 이 수를 제외하고 다른 두 수의 합으로 나타낼 수 있는가?
        FOR(j,n-1,0)
        {
            ll rem = A[i] - v[j];

            int lo = -1, hi = n-1;
            while (lo + 1 < hi)
            {
                if(v[mid] > rem) hi = mid;
                else lo = mid; 
            }

            if(lo != j && v[j] + v[lo] == A[i]) 
            {
                ans++;
                break;
            }
        }
    }

    cout << ans;
}