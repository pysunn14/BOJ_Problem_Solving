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

ll N,G,K; 

typedef struct {
    ll S;
    ll L;
    ll O;
    ll G; 
}object;

vector<object> objects;

bool check(ll x)
{
    ll sum = 0;
    for(auto& object : objects) 
    {
        object.G = object.S * max(1LL, x-object.L);
        sum += object.G;
    }
    sort(objects.begin(), objects.end(), [](object a, object b){
        return a.G > b.G;
    });
    
    int cnt = 0;

    for(const auto& object : objects) 
    {
        if(cnt == K) break; 
        
        if(object.O == 1)
        {
            cnt++;
            sum -= object.G;
        }
    }

    return (sum <= G); 
}

int main()
{
    fio();

    cin >> N >> G >> K;

    FOR(i,N,0)
    {
        ll S,L,O;
        cin >> S >> L >> O;
        objects.push_back({S,L,O});
    }

    ll lo = -1, hi = 5e9;        
    while(lo + 1 < hi)
    {
        if(!check(mid)) hi = mid;
        else lo = mid; 
    }

    int ans = hi;
    // check 
    if(!check(hi)) ans = lo; 
    cout << ans;
}