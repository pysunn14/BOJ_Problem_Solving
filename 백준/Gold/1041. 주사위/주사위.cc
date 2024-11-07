#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define pb push_back
#define pp pop_back
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define test(a) \
    int _;      \
    cin >> _;   \
    FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define weight first
#define vertex second
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

int main()
{
    fio();

    ll N; 
    cin>>N;
    int A[6];
    FOR(i,6,0) cin>>A[i];

    if(N == 1)
    {
        cout<<accumulate(A,A+6,0) - *max_element(A,A+6);
        return 0;
    }

    int value1 = *min_element(A, A+6);
    int value2 = INT_MAX;
    FOR(i,5,0)
    {
        FOR(j,6,i+1)
        {
            if((i == 0 && j == 5) || (i == 1 && j == 4) || (i == 2 && j == 3)) continue; 
            value2 = min(value2, A[i]+A[j]);
        }
    }

    int value3 = INT_MAX;
    value3 = min(value3, A[0]+A[1]+A[3]);
    value3 = min(value3, A[0]+A[1]+A[2]);
    value3 = min(value3, A[0]+A[2]+A[4]);
    value3 = min(value3, A[0]+A[4]+A[3]);
    value3 = min(value3, A[1]+A[2]+A[5]);
    value3 = min(value3, A[1]+A[3]+A[5]);
    value3 = min(value3, A[5]+A[3]+A[4]);
    value3 = min(value3, A[5]+A[2]+A[4]);

    //개수
    ll cube1 = (N-2)*(N-2)*5 + (N-2)*4;
    //?
    ll cube2 = 4 + (N-2)*8;
    //?
    ll cube3 = 4;

    cout<<cube1 * value1 * 1LL + cube2 * value2 * 1LL + cube3 * value3 * 1LL;
}