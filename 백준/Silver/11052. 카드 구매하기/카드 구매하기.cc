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

int d[1010];

int main()
{
    fio();

    int N; cin >> N;

    vector<int> P(N+1,0);
    FOR(i,N+1,1) cin >> P[i];

    // d[i] : 민규가 i원을 지불하기 위해서 필요한 금액의 최댓값이다.

    FOR(i,N+1,1)
    {
        FOR(j,i+1,1) d[i] = max(d[i], d[i-j] + P[j]); // i-j원
    }

    cout << d[N];

    // 카드가 i개 포함된 팩의 가격은 Pi 이다. 
}