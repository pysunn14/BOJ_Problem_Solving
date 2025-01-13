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

ll A[8][8];
ll up[8][8];

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
void change(int i, int j, char dir, int t, int &retFlag);

int main()
{
    fio();

    FOR(i,8,0) FOR(j,8,0) cin >> A[i][j];

    char dir; cin >> dir;
    int t = -1;

    // go
    switch (dir)
    {
    case 'U':
        t = 3;
        break;
    case 'D':
        t = 2;
        break;
    case 'R':
        t = 0;
        break;
    case 'L':
        t = 1;
        break;
    }

    if(dir == 'L')
    for(int j = 0 ; j < 8; j++)
    {
        // 위에서부터 한줄씩 올리는 작업을 진행한다
        for(int i =  0 ; i < 8 ; i++)
        {
            int retFlag;
            change(i, j, dir, t, retFlag);
            if (retFlag == 3)
                continue;
        }
    }

    else if(dir == 'R')
    for(int j = 7 ; j >= 0; j--)
    {
        // 위에서부터 한줄씩 올리는 작업을 진행한다
        for(int i = 0 ; i < 8 ; i++)
        {
            int retFlag;
            change(i, j, dir, t, retFlag);
            if (retFlag == 3)
                continue;
        }
    }

    else if(dir == 'U')
    for(int i = 0 ; i < 8; i++)
    {
        // 위에서부터 한줄씩 올리는 작업을 진행한다
        for(int j = 0 ; j < 8 ; j++)
        {
            int retFlag;
            change(i, j, dir, t, retFlag);
            if (retFlag == 3)
                continue;
        }
    }

    else 
    for(int i = 7 ; i >= 0; i--)
    {
        // 위에서부터 한줄씩 올리는 작업을 진행한다
        for(int j = 0 ; j < 8 ; j++)
        {
            int retFlag;
            change(i, j, dir, t, retFlag);
            if (retFlag == 3)
                continue;
        }
    }
    
    // output 
    FOR(i,8,0)
    {
        FOR(j,8,0) cout << A[i][j] << ' ';
        cout << '\n';
    }
}

void change(int i, int j, char dir, int t, int &retFlag)
{
    retFlag = 1;
    if (!A[i][j])
    {
        retFlag = 3;
        return;
    };

    bool upgrade = false;

    int r, c;
    r = i;
    c = j;

    // 최대한 위로 올린다
    while (true)
    {
        int nr = r + dr[t];
        int nc = c + dc[t];

        // 현재 벽에 도달했다면 종료한다
        if (nr < 0 || nr >= 8 || nc < 0 || nc >= 8) break;

        // 갈 수 있으면 간다
        if (!A[nr][nc])
        {
            A[nr][nc] = A[r][c];
            A[r][c] = 0;
        }
        // 위로 올라가는 도중에 숫자를 마주친다면?
        else if (A[nr][nc])
        {
            // 다른 숫자인 경우 그만둔다
            if (A[nr][nc] != A[r][c])
                break;
            // 같은 숫자인 경우 합쳐서 두배로 저장한다
            else
            {
                if (upgrade || up[nr][nc]) break;
                A[nr][nc] *= 2LL;
                A[r][c] = 0;
                upgrade = true;
            }
        }

        // 위치 변환
        r = nr;
        c = nc;
    }
    up[r][c] = upgrade;
}