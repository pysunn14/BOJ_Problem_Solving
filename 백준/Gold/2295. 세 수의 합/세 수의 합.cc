#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

set<ll> A;
map<pair<int,int>,ll> B;

int main()
{
    int N; cin >> N;

    ll U[1010];

    for(int i = 1 ; i <= N ; i++) cin >> U[i];
    sort(U + 1, U + N + 1);

    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= N ; j++)
        {
           A.insert(U[i] + U[j]); 
        }
    }
    
    ll ans = 0;

    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= N ; j++)
        {
            if(U[i] - U[j] >= 0 && A.find(U[i] - U[j]) != A.end())
            {
                ans = max(ans, U[i]);
            }
        }
    }
    
    cout << ans;
}