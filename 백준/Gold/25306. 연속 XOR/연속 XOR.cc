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

int main()
{
    fio();
    
    ll A,B; cin >> A >> B;
    
    // A이상 B이하인 수를 모두 XOR하여라. 일단 이거는 O(N)으로도 못품 
    ll res = 0;

    ll one = 0;

    // 짝 홀로 만들어줘.

    if(A % 2 == 0)
    {
        res = 0;
    }

    else 
    {
        res = A;
        A++;
    }
    
    if(B % 2 == 0)
    {
        res ^= B;
        B--;
    }
    
    if(A < B) one = B/2 - A/2 + 1;   
    if(one % 2 == 1) res ^= 1;    
    cout << res << '\n';
}