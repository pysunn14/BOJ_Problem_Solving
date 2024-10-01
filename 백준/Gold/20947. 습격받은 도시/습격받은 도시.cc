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

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
char A[2020][2020];
char M[2020][2020];
int N; 

void dfs(int t, int r, int c)
{
    int nr = r + dr[t];
    int nc = c + dc[t];

    if(nr >= 1 && nc >= 1 && nr <= N && nc <= N)
    {
        if(A[nr][nc] == '.') 
        {
            M[nr][nc] = 'N';
            dfs(t, nr, nc);
        }
    }
}

int main()
{
    fio();

    cin >> N;

    FOR(i,N+1,1)
    {
        string s; cin >> s;
        FOR(j,N,0)
        {
            A[i][j+1] = s[j];
        }
    }

    // 집이 있는 행 or 열은 절대 폭탄이 있었던 줄이 아니다. 그외 나머지 곳은 다 폭탄이 있었어도 괜찮다.

    FOR(i,N+1,1)
    {
        FOR(j,N+1,1)
        {
            if(A[i][j] == 'O')
            {
                int r = i;
                int c = j;

                FOR(t,4,0)
                {
                    dfs(t,r,c);
                }
            }
        }
    }

    // 비어있는 모든 곳을 폭탄으로 출력해도 괜찮다.

    // output

    FOR(i,N+1,1)
    {
        FOR(j,N+1,1)
        {
            if(M[i][j] == 'N') cout << '.';
            else if(A[i][j] == '.' ) cout << 'B';
            else cout << A[i][j];
        }
        cout<<'\n';
    }
}