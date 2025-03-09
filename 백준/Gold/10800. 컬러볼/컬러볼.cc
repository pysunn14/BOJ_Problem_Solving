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

int C[202020];
int S[202020];
int prefix_sum[202020];
int ans[202020];
int order[202020];

vector<pii> color[202020];
vector<pii> color_sum[202020];

int main()
{
    fio();
    
    int N; cin >> N;
    vector<pair<int,pii>> v(N+1 , {0,{0,0}}); // id, {값}

    FOR(i,N+1,1) cin >> C[i] >> S[i];

    // 나열 정렬
    FOR(i,N+1,1) v[i] = {i ,{S[i], C[i]}};

    // 벡터는 S 작은순으로 정렬한다.
    sort(all(v),[](pair<int,pii> a, pair<int,pii> b){
        return a.second.first < b.second.first;
    });

    FOR(i,N+1,1)
    {
        // 각 id가 배열에서 몇번째인가 
        int id = v[i].first;
        order[id] = i;
    }

    // 색깔별 전처리
    FOR(i,N+1,1) color[C[i]].push_back({i, S[i]});
    
    // 모든 색깔 정렬
    FOR(i,202020,0) sort(all(color[i]),[](pii a, pii b){
        return a.second < b.second;
    });

    // 색 누적합
    FOR(i,202020,0)
    {
        if(color[i].empty()) continue;
        color_sum[i].push_back({order[color[i][0].first], color[i][0].second});
        FOR(j,color[i].size(),1) color_sum[i].push_back({order[color[i][j].first], color_sum[i][j-1].second + color[i][j].second});
    }

    // 누적합 저장
    FOR(i,N+1,1) prefix_sum[i] = prefix_sum[i-1] + v[i].second.first; 
    
    // 정렬된 v벡터를 보면서 진행 
    FOR(i,N+1,1)
    {
        if(i == 1) 
        {
            ans[v[i].first] = 0;
            continue;
        }

        // 현재 값보다 작은 곳중 최대인 곳을 이분탐색으로 찾기, 누적합은 거기까지만 계산해주면 됨. 
        int lo = 0, hi = i;
        while (lo + 1 < hi)
        {
            if(v[mid].second.first >= v[i].second.first) hi = mid;
            else lo = mid;
        }

        int pos;
        if(v[hi].second.first < v[i].second.first) pos = hi;
        else pos = lo;

        pair<int,pii> vv = v[pos];

        int id = vv.first;
        int value = vv.second.first;

        // 현재 해당되는 컬러를 다 없애기 
        int cl = v[i].second.second;

        int k = -2;
        lo = -1, hi = color_sum[cl].size();

        while (lo + 1 < hi)
        {
            if(color_sum[cl][mid].first <= pos) lo = mid;
            else hi = mid;
        }
        if(color_sum[cl][hi].first <= pos) k = hi;
        else k = lo;

        // 색깔 리스트에서, 현재 pos이하의 좌표에 해당되는 색 누적합을 제거한다. 
        ans[v[i].first] = prefix_sum[pos];
        
        if(k >= 0) ans[v[i].first] -= color_sum[cl][k].second;

    }

    FOR(i,N+1,1) cout << ans[i] << '\n';
}