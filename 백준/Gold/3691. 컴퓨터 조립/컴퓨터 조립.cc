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

ll b; 
int n; 

typedef struct {
    ll price;
    ll quality;
}object;

map<string, vector<object>> obj;

set<string> categories;

void init()
{
    obj.clear();
    categories.clear();
}

bool check(ll quality)
{
    ll money = b;
    int recent_price = 0; 

    for(const auto& category : categories)
    {
        recent_price = 0;
        bool buy = false;
        for(const auto& object : obj[category])
        {
            // 예산이 아예 부족하거나, 퀄리티 보장 안되면 사지마 - 이거 문제있음 
            if(object.quality < quality || object.price > money + recent_price) continue; 
            
            if(!buy)
            {
                money -= object.price;
                recent_price = object.price;
                buy = true; 
            }
            
            else 
            {
                if(object.price >= recent_price) continue; 

                money += recent_price;
                money -= object.price;
                recent_price = object.price;
            }
        }

        if(!buy) return false;
    }

    return true;
}

int main()
{
    fio();
    
    test(t)
    {
        init();

        cin >> n >> b; 

        FOR(i,n,0)
        {
            string type, name;
            ll price, quality;
            
            cin >> type >> name >> price >> quality;
            categories.insert(type); 
            obj[type].push_back({price,quality});
        }

        ll lo = -1;
        ll hi = 1e9 + 1;

        while(lo + 1 < hi)
        {
            if(!check(mid)) hi = mid;
            else lo = mid;
        }

        ll ans = hi;
        if(!check(hi)) ans = lo;

        cout << lo << '\n';  
    }
}