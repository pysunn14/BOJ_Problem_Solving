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

vector<ll> prime;
set<ll> dup;
priority_queue<ll> pq;

int main()
{
    fio();

    int N, K; cin >> K >> N;

    ll mx = 0;
    
    FOR(i, K, 0)
    {
        ll x; 
        cin >> x;
        prime.push_back(x);

        pq.push(-x);
        dup.insert(x);
        mx = max(mx, x);
    }

    FOR(i,N,0)
    {
        if(i == N-1) cout << -pq.top();

        ll now = -pq.top();
        pq.pop();
        
        FORE(p, prime)
        {
            if(dup.find(abs(now * p)) != dup.end()) continue;

            if(pq.size() >= N && abs(now * p) > mx) continue;

            dup.insert(abs(now * p));

            pq.push(-abs(now * p));

            mx = max(mx, abs(now * p));
        }
    }
}