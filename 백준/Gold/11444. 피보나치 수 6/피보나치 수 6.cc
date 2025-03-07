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

const ll M = 1e9+7;

typedef vector<vector<ll>> matrix;

int N = 2;

matrix dot(matrix a, matrix b)
{
    matrix c;

    FOR(i, N, 0)
    {
        vector<ll> row(N, 0);
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

matrix fp(matrix a, ll b)
{
    if(b == 1) return a;
    if(b % 2 == 1) return dot(a, fp(a, b-1));
    
    matrix res = fp(a, b/2);
    return dot(res, res);
}

int main()
{
    fio();

    ll n; cin >> n;

    if(n == 1)
    {
        cout << 1;
        return 0;
    }

    // 피보나치를 행렬 방정식으로 나타내면 [fibo(n)] = [1 1, 1 0] fibo(n-1)

    matrix A = {{1,1},{1,0}};
    matrix B = {{1,0}};

    matrix fibo = fp(A, n-1);

    cout << fibo[0][0];
}