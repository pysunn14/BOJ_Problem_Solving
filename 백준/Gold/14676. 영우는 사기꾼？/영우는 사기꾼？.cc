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

// 3개 제한에 의해 정보가 많아봤자 30만
vector<int> graph[101010];

int indegree[101010];
// 건설 및 파괴 관리정보.
int cnt[101010];
// 지을 수 있는지 여부
bool ok[101010];

int main()
{
    fio();

    int N,M,K; cin >> N >> M >> K;

    FOR(i,M,0)
    {
        int X,Y; cin >> X >> Y;
        graph[X].push_back(Y);
        indegree[Y]++;
    }

    FOR(i,N+1,1)
    {
        // indegree가 0인 애들은 전부 ok 처리.
        if(!indegree[i]) ok[i] = true;
    }

    FOR(i,K,0)
    {
        int cmd, a;
        cin >> cmd >> a;

        // 건설 
        if(cmd == 1)
        {
            // 만약 순서상 가능하지 않은 건물이 지어졌을 경우
            if (indegree[a] > 0)
            {
                cout << "Lier!";
                exit(0);
            }

            // 정상 건설
            cnt[a]++;
            // 최초 건설이었다면 indegree에 영향이 있음.
            if(cnt[a] == 1) FORE(next, graph[a]) indegree[next]--;
        }

        // 파괴
        else if(cmd == 2)
        {
            // 만약 아직 건설되지 않은 건물이 파괴되었다면
            if(!cnt[a])
            {
                cout << "Lier!";
                exit(0);
            }

            // 정상 파괴
            else 
            {
                // 파괴함
                cnt[a]--;

                // 파괴 후 개수가 0이 되었다면
                if(!cnt[a])
                {
                    FORE(next, graph[a]) indegree[next]++;
                }
            }
        }
    }
    cout << "King-God-Emperor";
}