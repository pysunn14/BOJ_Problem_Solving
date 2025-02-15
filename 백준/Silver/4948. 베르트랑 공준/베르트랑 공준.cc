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

const int sz = 123456 * 2;
int cnt[sz + 1];

void sv()
{
    vector<bool> prime(sz + 1,true);
    prime[1] = false;
    for(int i = 2 ; i * i <= sz ; i++)
    {
        if(prime[i]) for(int j = i*i ; j <= sz; j += i) prime[j] = false;
    }

    for(int i = 1 ; i <= sz ; i++) 
    {
        cnt[i] = cnt[i-1];
        if(prime[i]) cnt[i]++;
    }
}

int main()
{
    fio();

    sv();

    while (true)
    {
        int n; cin >> n; if(!n) break;
        cout << cnt[2*n] - cnt[n] << '\n';
    }
      
}