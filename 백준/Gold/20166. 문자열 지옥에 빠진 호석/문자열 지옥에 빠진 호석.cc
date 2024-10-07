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
//                    11
int dr[8] = {0, 0, 1, -1, -1, 1, 1, -1};
int dc[8] = {1, -1, 0, 0, -1, 1, -1, 1};

char A[11][11];
int N,M,K; 
map<string, int> m;

void go(int r, int c, string s)
{
    s += A[r][c];
    m[s]++;

    if(s.size() == 5) return;

    // 상 하 좌 우 대각선
    FOR(t,8,0)
    {
        int nr = r + dr[t];
        if(nr > N) nr = 1;
        else if(nr < 1) nr = N;

        int nc = c + dc[t];
        if(nc > M) nc = 1;
        else if(nc < 1) nc = M;
        go(nr,nc,s);
    }
}

int main()
{
    fio();

    cin >> N >> M >> K;

    // 10, 10, 1000
    FOR(i,N+1,1)
    {
        string in; cin >> in;
        FOR(j,M,0)
        {
            A[i][j+1] = in[j];
        }
    }

    //전처리
    FOR(i,N+1,1) FOR(j,M+1,1) go(i,j,"");

    FOR(i,K,0)
    {
        // N과 M이 충분히 작으므로 완탐을 돌려볼 수 있을 것 같다.
        // 신이 좋아하는 문자열의 길이는 길어봐야 5글자이다. 
        // 그렇다면 가능한 모든 문자열에 대해서 가짓수를 전처리로 구하면 되지 않을까?
        string s; cin >> s;
        if(m[s] > 0) cout << m[s] << '\n';
        else cout << "0\n";
    }
}