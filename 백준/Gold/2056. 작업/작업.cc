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

int t[10101];
int f[10101];
vector<int> prior[10101];

int main()
{
    fio();
    int N; cin >> N;


    FOR(i,N+1,1)
    {
        cin >> t[i];

        // 선행관계 작업의 개수
        int cnt; 
        cin >> cnt;

        // 선행 작업
        FOR(j,cnt,0) 
        {
            int x; 
            cin >> x;
            prior[i].push_back(x);
        }
    }

    f[1] = t[1];

    FOR(i,N+1,2)
    {
        int max_f = 0;
        for(int j = 0 ; j < prior[i].size(); j++)
        {
            max_f = max(max_f, f[prior[i][j]]);
        }

        // prior에 존재하는 작업들 중 f가 최대인 값
        f[i] = max_f + t[i];
    }
    
    cout << *max_element(f + 1, f + N + 1);
}