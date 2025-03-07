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

typedef vector<vector<int>> matrix;

int N, M, P;

matrix dot(matrix a, matrix b)
{
    matrix c;

    FOR(i, N, 0)
    {
        vector<int> row(N, 0);
        c.push_back(row);
    }

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            for(int k = 0 ; k < N ; k++)
            {
                c[i][j] += (a[i][k] % M * b[k][j] % M) % M;
                c[i][j] %= M;
            }
        }
    }

    return c;
}

matrix fp(matrix a, int b)
{
    if(b == 1) return a;
    if(b % 2 == 1) return dot(a, fp(a, b-1));
    
    matrix res = fp(a, b/2);
    return dot(res, res);
}

int main()
{
    fio();

    while (true)
    {   
        cin >> N >> M >> P;

        if(!N && !M && !P) break;

        matrix A;
        
        FOR(i, N, 0)
        {
            vector<int> row(N, 0);
            A.push_back(row);

            FOR(j, N, 0) cin >> A[i][j];
        }

        matrix res = fp(A, P);

        FOR(i, N, 0)
        {
            FOR(j, N, 0)
            {
                cout << res[i][j] << ' ';
            }
            cout << '\n';
        }

        cout << '\n';
    }
}