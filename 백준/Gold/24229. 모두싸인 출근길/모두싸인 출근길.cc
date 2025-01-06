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

typedef struct 
{
    int L;
    int R;
    int ok;
}node;

struct Compare {
    bool operator()(const node& a, const node& b)
    {
        if(a.L == b.L) return a.R > b.R;
        return a.L > b.L;
    }
};

int main()
{
    fio();

    int N; cin >> N;
    vector<node> pan(N);
    FOR(i,N,0) cin >> pan[i].L >> pan[i].R;
    sort(all(pan), [](node a, node b)
        {
            if(a.L == b.L) return a.R < b.R;
            return a.L < b.L; 
        });

    priority_queue<node, vector<node>, Compare> pq;

    int NL = 0;
    int NR = 0;
    // 처음에 전처리로 선분 연결하기 : 연결완료된 선분은 pq에 삽입
    FORE(p, pan)
    {
        if(NR >= p.L) NR = max(NR, p.R);
        else 
        {
            if(pq.empty()) pq.push({NL,NR,1});
            else pq.push({NL,NR,0});
            NL = p.L;
            NR = p.R;
        }
    }
    pq.push({NL,NR,0});

    int ans = pq.top().R;
    // pq에서 하나씩 빼면서 탐색
    while (!pq.empty())
    {
        node now = pq.top(); pq.pop();
        if(now.ok == false) continue;

        vector<node> tmp;
        while (!pq.empty())
        {
            node next = pq.top();
            if(now.R - now.L >= next.L - now.R) 
            {
                pq.pop(); 
                ans = max(ans, next.R);
                tmp.push_back({next.L, next.R, 1});
            }
            else break;
        }
        FORE(t, tmp) pq.push(t);
    }
    cout << ans;
    return 0;
}