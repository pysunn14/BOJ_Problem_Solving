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

    ll N, K; cin >> N >> K;
    
    // 1부터 N까지 압도적 XOR 수의 개수는? 
    ll ans = 0;
    ll i = 1;
    
    // A를 잘 구성해보면 1111,,,,0000  이렇게 만든다쳐보셈 그러면 B는 0000.... 1111 이렇게됨 그걸를  << K를 하면 1111....00 이렇게 될수도 있잖아요 B가 하지만 여전히 B는 11111 (P-1) 이하여야합니다.

    // ll 128 
    while((1LL << (i)) <= N)
    {
        // i : 자리 개수 11111 -> i = 5
        if(i <= K) ans++; 
        else ans += (1LL << (i - K)); // 결국 A를 잘 구상하면 A가 5자리 이진숫자. 11111 = P-1   K=2   (11000... 11111) 얘만됨. 왜냐면 그래야지 반전 후에 옮겨도 
        i++;
    }

    ll a = 0;
    for( ; K > 0 && i > 0; K--, i--) a += (1LL << (i-1LL)); 
    if(N >= a) ans += (N-a + 1LL); 
    cout << ans; 
}