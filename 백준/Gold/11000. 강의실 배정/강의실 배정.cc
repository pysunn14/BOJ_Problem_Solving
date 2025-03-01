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

    int N; cin >> N;

    priority_queue<int, vector<int> , greater<int>> time;
    vector<pii> room;

    FOR(i, N, 0)
    {
        int s,e; cin >> s >> e;
        room.push_back({s,e});
    }

    sort(all(room),[](pii a, pii b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    
    time.push(room[0].second);
    
    for(int i = 1 ; i < N; i++)
    {
        int t = time.top(); time.pop();

        if(t <= room[i].first) time.push(room[i].second);
        else 
        {
            time.push(t);
            time.push(room[i].second);
        }
    }
    
    cout << time.size();
}