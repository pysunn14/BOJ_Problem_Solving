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

#define x first 
#define y second

long double dist(pair<long double, long double> a, pair<long double, long double> b)
{
    return sqrtl((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

long double d[1000];
int main()
{
    fio();

    cout << fixed;
    cout.precision(7);

    int N; cin >> N;

    vector<pair<long double, long double>> p(N);

    for(int i = 0 ; i < N ; i++) cin >> p[i].x >> p[i].y;

    sort(all(p),[](pair<long double, long double> a, pair<long double, long double> b){
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    // dp
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < i; j++)
        {
            // j는 i이전의 점 (i보다 x좌표가 작은 모든 점.)
            if(p[i].x == p[j].x) continue;
            d[i] = max(d[i], d[j] + dist(p[i], p[j]));
        }
    }

    cout << *max_element(d , d + N);
}