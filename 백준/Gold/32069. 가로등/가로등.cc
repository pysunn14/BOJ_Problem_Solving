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

    ll L,N,K; 

    cin >> L >> N >> K;
    ll A[303030];
    FOR(i,N+1,1) cin >> A[i];

    map<ll,ll> ans;
    vector<ll> line; 

    if(A[1] > 0) line.push_back(A[1]);
    if(A[N] < L) line.push_back(L - A[N]); 
    
    FOR(i,N,1)
    {
        ll diff = A[i+1] - A[i] - 1LL;
        
        if(diff & 1)
        {
            line.push_back(diff / 2LL + 1LL);
            if(diff != 1) line.push_back(diff / 2LL);
        }
        
        else 
        {
            line.push_back(diff / 2LL);
            line.push_back(diff / 2LL);
        }
    }
    sort(all(line));
    
    ans[0] = min(K,N);
    K -= min(K, N);

    ll now = 1;
    ll pointer = 0;
    
    while (K > 0)
    {
        while (line[pointer] < now && pointer < line.size()) pointer++;
        
        // 현재 line 개수만큼 vector에 추가 
        ans[now] = min(K, (ll)line.size() - pointer);

        K -= min(K, (ll)line.size() - pointer);
        now++;
    }

    for(auto [value, count] : ans) FOR(i, count, 0) cout << value << '\n';
}