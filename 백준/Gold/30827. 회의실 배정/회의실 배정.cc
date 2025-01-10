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

#define s first 
#define e second 

ll ans;
pii room[3] = {{-1,-1},{-1,-1},{-1,-1}};
int main()
{
    fio();

    int N,K; cin >> N >> K; 

    vector<pii> node;
    FOR(i,N,0)
    {
        int l,r;
        cin >> l >> r;        
        node.push_back({l,r});
    }

    sort(all(node),[](pii a, pii b){
        if(a.e == b.e) return a.s < b.s;
        return a.e < b.e;
    });

    // e를 기준으로 정렬
    int S, E;
    FOR(i,N,0)
    {
        S = node[i].s;
        E = node[i].e;
        
        // 넣을 수 있는 회의실이 있는지 체크
        int select = -1;
        int mx = -2;
        
        FOR(r, K, 0)
        {
            if(room[r].e >= S) continue;
            if(room[r].e > mx) 
            {
                mx = room[r].e;
                select = r;
            }
        }
        
        if(select == -1) continue;
        room[select].e = E;
        ans++;
    }

    cout << ans;
}