#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std; 

const int sz = 200000;

ll fact[sz];

int main()
{
    fact[1] = 1;
    for(int i = 2 ; i <= 10; i++) fact[i] = fact[i-1] * i;

    ll N, M, K; cin >> N >> M >> K;

    for(int i = 1 ; i <= K ; i++) 
    {
        long double up = 1;

        for(int j = 0 ; j < i; j++)
        {
            up *= (N-M-j);
        }

        long double down = 1; 

        for(int j = 0 ; j < i; j++)
        {
            down *= (N-j); 
        }

        cout << 1.0 - up/down << '\n';
    }

    return 0;
}