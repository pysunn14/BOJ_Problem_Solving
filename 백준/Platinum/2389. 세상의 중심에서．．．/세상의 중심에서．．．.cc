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

double x[100], y[100];
double xx, yy, r;
double alpha = 0.05;

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main()
{
    fio();

    int N; cin >> N;

    FOR(i,N,0)
    {
        cin >> x[i] >> y[i];
        xx += x[i];
        yy += y[i];
        // N명의 사람들을 모두 포함하는 원의 중심에 있으면 되는데, 단 반지름이 최소여야 한다.
    }
    
    // 중심
    xx /= (double)N;
    yy /= (double)N;
    
    FOR(i,30303,0)
    {
        double mx = 0;
        int idx = 0;
        // 거리가 가장 먼 점 찾기
        FOR(j,N,0)
        {
            double now = dist(xx, yy, x[j], y[j]);
            if(now > mx) 
            {
                mx = now;
                idx = j;
            }   
        }       

        r = mx;
        // 먼 점으로 이동
        xx += (x[idx] - xx) * alpha;
        yy += (y[idx] - yy) * alpha;
        alpha *= 0.999;
    }

    cout << xx << ' ' << yy << ' ' << r;    
}