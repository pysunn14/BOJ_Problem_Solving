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

char S[10101][505];
char A[10101][505];

// 그럼 백트래킹을 해서 안되는 경로면 c를 취소해볼 수 있을 것같음
int ans = 0;
int R,C; 

bool go(int r, int c)
{
    A[r][c] = 'c';

    if(c == C-1)
    {
        ans++;
        return true;
    }

    bool ok = false;

    if(r - 1 >= 0 && A[r - 1][c + 1] == '.')
    {
        ok |= go(r-1, c+1);
    }

    if(A[r][c + 1] == '.' && !ok)
    {
        ok |= go(r, c+1);
    }

    if(r + 1 < R && A[r + 1][c + 1] == '.' && !ok)
    {
        ok |= go(r+1, c+1);
    }

    return ok;
}

int main()
{
    fio();

    cin >> R >> C;

    FOR(i,R,0)
    {
        string s; cin >> s;

        FOR(j,C,0)
        {
            S[i][j] = s[j];
        }
    }

    FOR(i,R,0) FOR(j,C,0) A[i][j] = S[i][j];

    // 위에서 먼저 체크
    FOR(i,R,0)
    {
        int r = i;
        int c = 0; 
        go(i,0);

    }

    cout << ans;
}