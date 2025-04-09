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

int N,M,K; 
vector<int> v;
string ans;

bool check(int dist)
{
    int cnt = 1;
    int last = v[0];
    ans = string(K, '0');
    ans[0] = '1';

    for(int i = 1 ; i < K ; i++)
    {
        if(cnt == M) break;

        // 스위핑 

        // 아직 방문하지 않은 위치 - 방문 
        // 단, 최근 위치와 거리가 dist 이하이어야함. 
        
        if(v[i] - last < dist) 
        {
            ans[i] = '0';
            continue;
        }

        cnt++;
        last = v[i];
        ans[i] = '1';
    }
    
    // M개를 방문하지 못했으면 false 
    if(cnt < M) return false;
    return true;
}

int main()
{
    fio();

    cin >> N >> M >> K;

    v.resize(K);
    FOR(i, K, 0) cin >> v[i];
    
    // 가장 가까운 두 심판의 거리를 최대화 - 이분탐색 
    int lo = 0, hi = 1e9;

    while (lo + 1 < hi)
    {
        if(check(mid)) lo = mid;
        else hi = mid;
    }

    if(check(hi)) cout << ans;
    else check(lo); cout << ans;
}