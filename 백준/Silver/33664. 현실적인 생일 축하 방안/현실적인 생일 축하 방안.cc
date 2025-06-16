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

    ll B,N,M; cin >> B >> N >> M;

    map<string,ll> m;

    for(int i = 1 ; i <= N; i++)
    {
        string s; cin >> s;
        ll money; cin >> money;
        m[s] = money;
    }

    ll sum = 0;
    for(int i = 1 ; i <= M; i++)
    {
        string s; cin >> s; 
        sum += m[s];
    }
    
    if(sum <= B) cout << "acceptable";
    else cout << "unacceptable";
}