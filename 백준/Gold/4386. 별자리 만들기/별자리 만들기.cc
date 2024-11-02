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
    double x,y;
}star; 

double getdist(star a, star b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int parent[101];
int find(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b)
{
    if(a!=b)
    {
        a = find(a);
        b = find(b);
        if(a < b) parent[b] = a;
        else parent[a] = b;
    }
}

int n; 
vector<star> stars;
vector<pair<double,pii>> d; // s -> e 로 가는 거리값
double ans;

void MST()
{
    FOR(i,101,0) parent[i] = i;

    // 모든 거리를 구해주고 저장해두기
    FOR(i,n,1)
    {
        FOR(j,n+1,i)
        {
            d.push_back({getdist(stars[i],stars[j]),{i,j}});
        }
    }

    // kruska
    sort(all(d));

    // n-1번 반복하면 간선이 모두 만들어졌다.
    int cnt = 0;
    // 거리가 가장 작은 것부터 간선을 만들어간다.
    FORE(dist, d)
    {
        int i = dist.second.first;
        int j = dist.second.second;
        if(find(i) == find(j)) continue;

        merge(i,j);
        ans += dist.first;
        cnt++;
        if(cnt == n-1) break;
    }
}

int main()
{
    fio();
    cin >> n;

    stars.push_back({0,0});

    FOR(i,n,0)
    {
        double x,y; 
        cin >> x >> y;
        stars.push_back({x,y});
    }

    MST();
    cout << fixed;
    cout.precision(2);
    cout << ans;
}