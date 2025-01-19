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
    double x;
    double y;
}node;

double dist(node a, node b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

vector<node> A[1010101];
vector<double> D[1010101];
vector<node> p;

int main()
{
    fio();
    
    int N; 
    cin >> N;

    FOR(i, N, 0)
    {
        double x, y;
        cin >> x >> y;
        p.push_back({x,y});
    }
    
    sort(all(p), [](node a, node b){
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;    
    });
    
    int row = 0;
    A[row].push_back(p[0]); 

    FOR(i, N, 1)
    {
        if(A[row].empty()) continue;
        
        if(A[row][0].x < p[i].x) row++;

        A[row].push_back(p[i]);
        D[row].push_back(0);
    }
    
    FOR(j, A[0].size(), 0) D[0][j] = 0;
    
    FOR(i, row+1, 1)
    {
        FOR(j, A[i].size(), 0)
        {
            // j는 i보다 x좌표가 작은 점이기는 한데, 그런 점 중에서는 바로 전 단계에서 오는 점.
            D[i][j] = max(D[i][j], max(D[i-1][0] + dist(A[i-1][0], A[i][j]), D[i-1][A[i-1].size()-1] + dist(A[i-1][A[i-1].size()-1], A[i][j])));
        }
    }
    
    cout << fixed;
    cout.precision(7);
    
    // dp 마지막에서 최댓값 출력
    cout << *max_element(all(D[row]));
}