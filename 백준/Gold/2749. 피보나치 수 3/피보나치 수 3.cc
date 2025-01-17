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

#define matrix vector<vector<ll>>

const ll mod = 1e6;

// 행렬 a와 행렬 b를 곱해주는 함수
matrix mul(matrix & a, matrix & b)
{
    vector<ll> row(2,0);
    matrix res(2,row);

    FOR(i,2,0)
    {
        FOR(j,2,0)
        {
            FOR(k,2,0)
            {
                //a의 행 요소와 b의 열 요소를 곱해주면 된다.
                res[i][j] += (a[i][k] * b[k][j]) % mod;
                res[i][j] %= mod;
            }
        }
    }
    
    return res;
}

// 행렬 a를 b번 제곱해준다
matrix dnq(matrix & a, ll b) 
{
    if(b == 1) return a;
    
    else if(b % 2 == 0)
    {
        matrix res = dnq(a, b/2);
        return mul(res, res);
    }
    
    else if(b % 2 == 1)
    {
        matrix res = dnq(a, b-1);
        return mul(a, res);
    }
}

int main()
{
    fio();

    ll n; 
    cin >> n;

    if(n <= 1) 
    {
        cout << n;
        return 0;
    }

    matrix A;
    matrix B;

    A.push_back({1,1});
    A.push_back({1,0});

    B.push_back({0,0});
    B.push_back({1,0});  
    
    matrix res = dnq(A, n);
    cout << mul(res, B)[0][0] % mod;
}