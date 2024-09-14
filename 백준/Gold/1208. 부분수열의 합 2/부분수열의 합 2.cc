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
    int N, S; cin >> N >> S;
    vector<int> A;
    vector<int> B;

    FOR(i,N/2 + 1,1)
    {
        int x; cin >> x;
        A.push_back(x);
    }

    FOR(i,N + 1,N/2 + 1)
    {
        int x; cin >> x;
        B.push_back(x);
    }

    // 가능한 합의 조합을 모두 저장
    vector<ll> sumA;
    vector<ll> sumB;

    FOR(now,1 << A.size(), 0)
    {
        ll sum = 0;
        FOR(i,A.size(),0) if((now >> i) & 1) sum += A[i];
        sumA.push_back(sum);
    }

    // B에 대한 부분 수열의 합 계산
    FOR(now, 1 << B.size(), 0)
    {
        ll sum = 0;
        FOR(i,B.size(),0) if((now >> i) & 1) sum += B[i];
        sumB.push_back(sum);
    }

    // 이분 탐색을 위한 정렬
    sort(all(sumA));
    sort(all(sumB));

    ll ans = 0;
    FORE(a,sumA)
    {
        //크기가 양수인 부분수열만 생각해야 함.
        int cnt = ub(all(sumB), S - a) - lb(all(sumB), S - a);
        ans += cnt;
    }
    if(!S) ans--;
    cout<<ans;
}