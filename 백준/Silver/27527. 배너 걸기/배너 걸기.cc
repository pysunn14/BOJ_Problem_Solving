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

int A[202020];
int max_number[202020];

int main()
{
    fio();
    int N,M; cin >> N >> M;
    ll need = ceil(0.9 * M);

    FOR(i,N+1,1) cin >> A[i]; 
    map<int, int> cnt;

    // 1번부터 1 + M - 1번까지 등장하는 숫자들의 빈도를 저장한다.
    FOR(i,1+M,1) cnt[A[i]]++;

    int mx = 0;
    FORE(a, cnt) mx = max(mx, a.second);
    if(mx >= need)
    {
        cout<<"YES";
        return 0;
    }

    // 다음 구간부터 등장하는 빈도를 수정하면서 최대 빈도수가 need이상인지를 판별한다.
    for(int lo = 2, hi = lo + M - 1; hi <= N; lo++, hi++)
    {
        cnt[A[lo - 1]]--;
        cnt[A[hi]]++;

        int mx = cnt[A[hi]];

        if(mx >= need)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}