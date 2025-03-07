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

vector<ll> v;

int main()
{
    fio();
    
    ll N, X;
    cin >> N >> X;
    
    ll low = 0;
    ll cnt = 0;

    FOR(i,N,0) 
    {
        ll x; cin >> x;
        if(x >= X) cnt++;
        else v.push_back(x);
    }
    
    sort(all(v));

    int i = 0 ;
    int j = v.size() - 1;
    
    while(i <= j)
    {
        if(i != j && (v[i] + v[j]) * 2LL >= X)
        {
            cnt++;
            i++;
            j--;
        }

        else
        {
            low++;
            i++;
        }
    }
        
    cout << low / 3LL + cnt;
}