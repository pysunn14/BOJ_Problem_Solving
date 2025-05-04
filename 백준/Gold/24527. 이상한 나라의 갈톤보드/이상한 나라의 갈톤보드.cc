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

const int sz = 101010;

double A[sz];
double S[sz];
double tree[sz * 4];

double f(double a, double b)
{
    return a + b;
}

double init(int lo, int hi, int node)
{
    if (lo == hi)
        return tree[node] = S[lo];
    return tree[node] = f(init(lo, mid, node * 2), init(mid + 1, hi, node * 2 + 1));
}

double query(int lo, int hi, int node, int left, int right)
{
    if (left > hi || right < lo)
        return 0;
    if (left <= lo && hi <= right)
        return tree[node];
    return f(query(lo, mid, node * 2, left, right), query(mid + 1, hi, node * 2 + 1, left, right));
}

ll value(ll floor)
{
    return floor * (floor + 1LL) / 2LL;
}

int main()
{
    fio();

    cout << fixed << setprecision(4);

    int H; cin >> H;

    int Q,R; cin >> Q >> R;

    while (Q--)
    {
        // 구슬 떨어뜨리기 
        ll a;
        double b; 
        cin >> a >> b;

        // 떨어뜨릴 구간 찾기. 
        ll lo = 0;
        ll hi = H + 1;
        
        ll floor;
        while (lo + 1 < hi)
        {
            // 만약 현재 보는 구간이 들어오고 있다면 리턴 하고 아닌경우? 

            if(value(mid-1) < a && a <= value(mid)) 
            {
                floor = mid;
                break;
            }

            else if(a > value(mid)) lo = mid;
            else hi = mid;
        }
        
        int idx = floor - ((floor * (floor + 1) / 2) - a);
        int s = idx, e = s + H - floor + 1;
         
        A[s] += b / (e - s + 1.0);
        A[e+1] -= b / (e - s + 1.0);
    }
    
    // pfsum
    FOR(i,H+2,1) S[i] = S[i-1] + A[i];

    // init
    init(1, H+1, 1);
    
    while (R--)
    {
        int a, b; 
        cin >> a >> b;
        
        // a부터 b까지 구간 쿼리? 
        cout << query(1, H+1, 1, a, b) << '\n';
    }    
}