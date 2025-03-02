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
ld xx, yy;
ld ans;

ld x[1010];
ld y[1010];

ld dist(ld x1, ld y1, ld x2, ld y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

ld custom_round(ld value)
{
    return round(value * 1000l / 1000l);
}

ld correction(ld value)
{
    ld epsilon = 1e-9;
    if(fabsl(value) < epsilon) return 0l;
    return value;
}

int main()
{
    fio();

    int N; cin >> N;

    FOR(i, N, 0)
    {
        cin >> x[i] >> y[i];
        xx += x[i];
        yy += y[i];
    }

    xx /= N;
    yy /= N;

    for(int i = 0 ; i < 30303 ; i++)
    {
        int idx = 0;
        ld mx = 0;
        for(int j = 0 ; j < N; j++)
        {
            if(dist(xx,yy,x[j],y[j]) > mx)
            {
                idx = j; 
                mx = dist(xx,yy,x[j],y[j]);
            }
        }
        ans = mx;

        xx += (x[idx] - xx) * alpha;
        yy += (y[idx] - yy) * alpha;
        alpha *= 0.999;
    }

    cout << fixed << setprecision(3);
    cout << correction(xx) << ' ' << correction(yy) << '\n';
    cout << correction(ans);
}