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

typedef long double ld;

ld alpha = 0.1;
ld diameter;
ld xx, yy;

ld dist(ld x1, ld y1, ld x2, ld y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main()
{
    fio();

    int N;
    cin >> N;

    vector<pair<ld,ld>> pos(N);

    FOR(i,N,0) 
    {
        cin >> pos[i].first >> pos[i].second;

        xx += pos[i].first;
        yy += pos[i].second;
    }

    xx /= (ld)N;
    yy /= (ld)N;

    // 초기 위치는 평균값으로 설정
    for(int i = 0 ; i < 50505 ; i++)
    {
        int idx = 0;
        ld mx = 0;

        for(int i = 0 ; i < N ; i++)
        {
            ld dis = dist(xx, yy, pos[i].first, pos[i].second);

            if(mx < dis)
            {
                mx = dis;
                idx = i;
            }
        }

        diameter = 2*mx;
        
        // move
        xx += (pos[idx].first - xx) * alpha;
        yy += (pos[idx].second - yy) * alpha;
        alpha *= 0.999;
    }

    cout << fixed;
    cout.precision(2);
    cout << diameter;
}