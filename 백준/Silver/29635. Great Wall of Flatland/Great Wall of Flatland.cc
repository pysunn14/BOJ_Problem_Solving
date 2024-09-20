#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pii pair<double, double>
#define test(a) int _; cin >> _; FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

double dist(pii a, pii b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

#define Line pair<pii,pii>

// 등장한 라인
set<Line> line;

// 중복 라인
set<Line> dpline;

set<Line> ndpline;

void insertLine(Line a, Line b)
{
    if(line.find(a) == line.end() && line.find(b) == line.end()) line.insert(a);

    else
    {
        dpline.insert(a);
    }
}

int main()
{
    fio();
    // 중복이 없는 라인
    double ans = 0;
    int m; cin>>m;

    vector<Line> v;

    FOR(i,m,0)
    {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        Line t11 = {{x1,y1},{x2,y2}}, t12 = {{x2,y2},{x1,y1}};
        Line t21 = {{x2,y2},{x3,y3}}, t22 = {{x3,y3},{x2,y2}};
        Line t13 = {{x1,y1},{x3,y3}}, t31 = {{x3,y3},{x1,y1}};

        insertLine(t11,t12);
        insertLine(t21,t22);
        insertLine(t31,t13);

        v.push_back(t11);
        v.push_back(t21);
        v.push_back(t31);
    }

    FORE(p, v)
    {
        if(dpline.find(p) == dpline.end() && dpline.find({p.second, p.first}) == dpline.end()) 
        {
            ndpline.insert(p);
        }
    }

    // M개의 삼각형이 있으니까 선분은 3000개가 있다.
    cout<<fixed;
    cout.precision(4);

    FORE(L, ndpline)
    {
        ans += dist(L.first, L.second);
    }
    cout<<ans;
}