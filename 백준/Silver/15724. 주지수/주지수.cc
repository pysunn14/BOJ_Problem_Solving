#include <bits/stdc++.h>
#define pii pair<int, int>
#define test(a) \
    int _;      \
    cin >> _;   \
    FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

ll S[1026][1026];
ll Q[1026][1026];
ll A[1026][1026];

int main()
{
    fio();

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            S[i][j] = 0;
            Q[i][j] = 0;
            cin >> A[i][j];
        }
    }

    // init
    for (int i = 1; i <= N; i++)
    {
        S[i][1] = A[i][1];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 2; j <= M; j++)
        {
            S[i][j] = S[i][j-1] + A[i][j];
        }
    }


    // 두번째
    for (int j = 1; j <= M; j++)
    {
        for (int i = 2; i <= N; i++)
        {
            S[i][j] = S[i-1][j] + S[i][j];
        }
    }

    int k = 0;
    cin >> k;

    int x1, y1, x2, y2;
    
    for (int i = 0; i < k; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1] << '\n';
    }
}