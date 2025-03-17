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
    
    int N;; cin >> N;

    double B[7];
    double A[7][7];

    FOR(i,N+1,1)
    {
        FOR(j,N+1,1) cin >> A[i][j];
        cin >> B[i];
    }

    // 모든 행을 0으로 처리한다.

    // 어떤 열에 대해서
    for(int pivot = 1 ; pivot <= N; pivot++)
    {
        //pivot 아래 -> 0으로 만들어주기
        for(int r = pivot + 1 ; r <= N ; r++)
        {
            // 1st
            double coef = (-1.0) * A[r][pivot] / A[pivot][pivot];
            
            // 모든 행 요소에 대해서 적용시키기
            for(int c = pivot ; c <= N ; c++) A[r][c] += coef * A[pivot][c]; 

            // B
            B[r] += coef * B[pivot]; 
        }
    }

    double ans[7];

    // 아래쪽부터 올라가면서 계산한다.
    for(int r = N ; r >= 1; r--)
    {
        // 빼기
        for(int c = N ; c > r; c--) B[r] -= A[r][c] * ans[c];

        // 나누기
        ans[r] = B[r] / A[r][r];
    }

    // output
    FOR(i,N+1,1) cout << ans[i] << ' ';
}