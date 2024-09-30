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

typedef __float128 ff;

constexpr ff PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647Q;
constexpr ff threshold = 0.0000000000000000000000000001Q; //28까지만 가능함

ff A,B,C;

const int n = 200;
ff dp[n];

void facto()
{
    dp[1] = 1;
    FOR(i,n+1,2) dp[i] = dp[i-1] * i;   
}

ff fpow(ff a, int b)
{
    if(b == 1) return a;
    if(b % 2 == 0) return fpow(a, b/2) * fpow(a, b/2);
    if(b % 2 == 1) return fpow(a, b-1) * a;
}

ff fsin(ff x)
{
    // period 
    if(x > 2 * PI)
    {
        ll cnt = x / (2*PI); 
        x -= 2*PI*cnt;
    }

    ff sum = 0;

    //talyor series
    int i = 0;
    int sign = 1;

    for(int i = 1 ; (2 * i - 1) <= n; i++) 
    {
        sum += sign * fpow(x,2*i-1) / dp[2*i-1];
        sign *= -1;
    } 
    return sum;
}

ff f(ff x)
{
    return A * x + B * fsin(x);
}

int main()
{
    fio();

    facto();

    double a,b,c;
    cin >> a >> b >> c;
    A = a; B = b; C = c;

    ff lo = (C - B)/A - 1, hi = (C + B)/A + 1;
    ff ans;

    while (true)
    {
        if(((f(mid) - C) > 0 && (f(mid) - C) <= threshold )||((f(mid)-C) < 0 && (f(mid)-C) >= -threshold ))
        {
            break;
        }
        else if(f(mid) > C) hi = mid;
        else lo = mid;
    }
    ans = hi;

    // output
    ll integer_part = (ll)ans;
    if(!integer_part) ans += 1;

    ll result = ans * 1e7;
    if(result % 10 >= 5) result += 10;

    // 정수 부분 출력
    cout << integer_part << '.';
    result /= 10;

    vector<int> dec;

    // 소수 부분 출력
    FOR(i,6,0)
    {
        dec.push_back(result % 10);
        result /= 10;
    }

    reverse(all(dec));

    FORE(d,dec) cout << d;
}

