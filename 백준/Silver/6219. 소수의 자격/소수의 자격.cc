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

int ans;
int A,B,D; 
bool prime[4040404];
void sieve()
{
    fill(prime, prime + 4040404, true);
    prime[1] = false;
    for (int i = 2; i * i <= B ; i++) if(prime[i]) for(int j = i * i; j <= B; j += i) prime[j] = false;

    // A~B 
    FOR(i, B+1, A)
    {
        if(prime[i])
        {
            int num = i;
            // // 숫자가 D를 포함하고 있는지 확인
            while (num > 0)
            {
                int r = num % 10;
                if(r == D) 
                {
                    ans++;
                    break;
                }
                num /= 10;
            }   
        }
    }

    cout<<ans;
}

int main()
{
    fio();
    cin>>A>>B>>D;
    sieve();
}