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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

ll A[252525];
ordered_set OS;
void m_erase(ordered_set &OS, int val)
{
 int index = OS.order_of_key(val);
 auto it = OS.find_by_order(index);
 if(*it == val) OS.erase(it);
}

int main()
{
    fio();

    int N,K; cin >> N >> K;
    FOR(i,N+1,1) cin >> A[i];

    // 길이가 K인 부분수열에서 (K+1) / 2번째 숫자의 합을 출력한다.
    int m = (K+1)/2;
    ll ans = 0;

    for(int i = 1 ; i <= K; i++) OS.insert(A[i]);
    ans += (ll)*OS.find_by_order(m-1);

    //처음 넣기
    for(int i = 2 ; i + K - 1 <= N ; i++)
    {
        m_erase(OS, A[i-1]);
        OS.insert(A[i+K-1]);
        ans += (ll)*OS.find_by_order(m-1);
    }
    cout << ans;
}