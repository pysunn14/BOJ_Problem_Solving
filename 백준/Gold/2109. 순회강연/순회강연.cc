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

ll ans;

vector<int> score[10101];

priority_queue<int> pq;

int main()
{
    fio();

    int N; cin >> N;

    int mx_day = 0;

    FOR(i,N,0)
    {
        int p,d;
        cin >> p >> d;
        score[d].push_back(p);

        mx_day = max(mx_day, d);
    }

    for(int i = mx_day ; i >= 1; i--)
    {
        FORE(sc , score[i]) pq.push(sc);

        if(pq.empty()) continue;
        ans += pq.top(); pq.pop();
    }
    
    cout << ans;
}