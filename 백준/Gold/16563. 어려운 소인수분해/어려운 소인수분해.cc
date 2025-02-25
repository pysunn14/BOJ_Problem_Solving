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


const int M = 5000000;
vector<int> fac[M+1];

int main()
{
    fio();

    int N; cin >> N;

    int k[1010101]; FOR(i,N+1,1) cin >> k[i];

    vector<int> prime(M+1);

    for(int i = 1 ; i <= M; i++) prime[i] = i;
    
    for(int i = 2 ; i * i <= M ; i++) if(prime[i] == i) for(int j = 2 ; j*i <= M ; j++) if(prime[i*j] == i*j) prime[i*j] = i;

    for(int i = 2 ; i <= M ; i++)
    {
        int k = i;
        while (k > 1)
        {
            fac[i].push_back(prime[k]);
            k /= prime[k];
        }
    }

    FOR(i,N+1,1)
    {
        FORE(f, fac[k[i]]) cout << f << ' ';
        cout << '\n';
    }

}