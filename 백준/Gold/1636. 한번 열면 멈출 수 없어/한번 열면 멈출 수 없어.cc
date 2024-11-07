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

ll s[101010],e[101010];
int main()
{
    fio();

    int N; cin >> N;
    vector<pair<ll,ll>> range;
    FOR(i,N+1,1) cin >> s[i] >> e[i];

    ll left = s[1];
    ll right = e[1];

    ll cnt = 1;
    ll init = -1;

    FOR(i, N+1, 2)
    {
        if(right < s[i])
        {
            if(init == -1) init = right;
            FOR(j,cnt,0) 
            {
                range.push_back({left,right});
            }
            left = s[i], right = s[i];
            cnt = 1;
        }

        else if(left > e[i])
        {
            if(init == -1) init = left;
            FOR(j,cnt,0) range.push_back({left,right});
            left = e[i], right = e[i];
            cnt = 1;
        }

        else 
        {
            left = max(left, s[i]);
            right = min(right, e[i]);
            cnt++;
        }
    }

    //cnt남아있으면 푸시
    FOR(j,cnt,0) range.push_back({left,right});
    if(init == -1) init = range.back().first;

    vector<int> move;
    ll sum = 0;
    FOR(i, N, 1)
    {
        if (range[i - 1].first > range[i].second)
        {
            move.push_back(range[i].second - range[i-1].first);
        }

        else if (range[i - 1].second < range[i].first)
        {
            move.push_back(range[i].first - range[i-1].second);
        }

        else
        {
            move.push_back(0);
        }
    }

    FORE(m, move) sum += llabs(m);

    cout << sum << '\n';
    cout << init << '\n';
    FORE(m, move)
    {
        cout << init + m << '\n';
        init += m;
    }
}