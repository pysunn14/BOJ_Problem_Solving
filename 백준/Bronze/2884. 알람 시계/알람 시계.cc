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

    int H,M; cin >> H >> M;

    // 45분 앞선 시각을 출력하면 됩니다. 
    
    // H와 M을 같이 환산 

    int now = 60 * H + M;

    int next = now - 45;

    if(next < 0)
    {
        cout << 23 << ' ' << 60 + next << '\n';
    }

    else 
    {
        cout << next / 60 << ' ' << next % 60 << '\n';
    }
}