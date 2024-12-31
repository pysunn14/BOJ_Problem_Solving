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

ll n,m,A; 
int get_ans(ll a)
{
    int ans;
    if(a % n == 0 || a % m == 0) ans = 1;
    else if(n > a || m > a) ans = 2;
    else 
    {
        ans = 3;
        // N로 다 나눠보고 남은b에 대해 배수판정
        for(ll k = 1; n*k < a; k++)
        {
            if((a-n*k) % (m-k) == 0) ans = 2;
        }
        
        for(ll k = 1; m*k < a; k++)
        {
            if((a-m*k) % (n-k) == 0) ans = 2;
        }
    }
    return ans;
}

int main()
{
    fio();
    cin >> n >> m >> A;
    cout << min(get_ans(A), get_ans(n*m-A));
}