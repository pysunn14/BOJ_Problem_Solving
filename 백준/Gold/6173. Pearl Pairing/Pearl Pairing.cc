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

    int N,C; cin >> N >> C;

    priority_queue<pii> pq;
    
    FOR(i,C+1,1) 
    {
        int c; cin >> c; 
        pq.push({c,i});
    }

    while (!pq.empty())
    {
        pii a = pq.top();
        pq.pop();
        pii b = pq.top();
        pq.pop();

        cout << a.second << ' ' << b.second << '\n';

        if(a.first > 1) pq.push({a.first-1, a.second});
        if(b.first > 1) pq.push({b.first-1, b.second});
    }
}