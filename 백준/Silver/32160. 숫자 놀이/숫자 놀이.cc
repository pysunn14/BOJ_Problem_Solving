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

int main()
{
    fio();
    int N; cin>>N;

    vector<pii> order;

    priority_queue<int> pq;

    FOR(i,N,1) pq.push(i);

    int r = 0;
    while (!pq.empty())
    {
        int a = pq.top(); pq.pop();
        if(pq.empty()) 
        {
            r = a;
            break;
        }
        
        int b = pq.top(); pq.pop();
        order.push_back({a,b});
        pq.push(a-b);
    }

    cout << N - r << '\n';
    FORE(o, order) cout<<o.first << ' ' << o.second << '\n';
    cout << N << ' ' << r;
}