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
    int N, M; cin >> N >> M;
    priority_queue<int> p;
    priority_queue<int> m;

    FOR(i, N, 0) 
    {
        int x; cin >> x;
        if(x > 0) p.push(x);
        else m.push(-x);
    }

    ll ans = 0;
    ll plast = 0;
    ll mlast = 0;

    vector<int> pmax;
    vector<int> mmax;

    for(int i = 0 ; i < M && !p.empty(); i++)
    {
        pmax.push_back(p.top());
        p.pop();
    }
    sort(all(pmax));
    
    for(int i = 0 ; i < M && !m.empty(); i++)
    {
        mmax.push_back(m.top());
        m.pop();
    }
    sort(all(mmax));
    
    if(!pmax.empty())
    {
        plast += pmax[0];
        FOR(i, pmax.size(), 1)
        {
            plast += (pmax[i] - pmax[i-1]);
        }   
    }

    if(!mmax.empty())
    {
        mlast += mmax[0];
        FOR(i, mmax.size(), 1)
        {
            mlast += (mmax[i] - mmax[i-1]);
        }
    }

    if(plast > mlast)
    {
        ans += plast;
        FORE(e, mmax) m.push(e);
    }

    else
    {
        ans += mlast;
        FORE(e, pmax) p.push(e);
    }

    // 각 배열마다 M개씩 묶어서 두배한 것으로 답에 더해주기
    while (!p.empty())
    {
        // M개 묶어서 답에 더하기
        ans += p.top() * 2;
        p.pop();
        for(int i = 0 ; i < M-1 && !p.empty(); i++) p.pop();
    }

    while (!m.empty())
    {
        // M개 묶어서 답에 더하기
        ans += m.top() * 2;
        m.pop();

        for(int i = 0 ; i < M-1 && !m.empty(); i++) m.pop();
    }

    // 남은 것들 M개씩 묶어서 넣기
    cout << ans;
}