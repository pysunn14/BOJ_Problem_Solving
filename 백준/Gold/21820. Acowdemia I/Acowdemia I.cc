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

int A[100001];
int B[100001];
int main()
{
    fio();

    int N,L; cin >> N >> L;

    FOR(i,N+1,1) cin >> A[i];
    FOR(i,N+1,1) B[A[i]]++;
    sort(A + 1, A+1+N);

    for(int i = 100000 ; i >= 2; i--) B[i-1] += B[i];

    // B[i] : i이상인 논문이 몇개인가
    int i = 0;
    for(i = 100000 ; i >= 1; i--) if(B[i] >= i) break;
    if((upper_bound(A+1,A+1+N, i) - lower_bound(A+1,A+1+N , i)) >= i + 1 - B[i+1] && L >= i+1 - B[i+1]) i++;
    cout << i;
}