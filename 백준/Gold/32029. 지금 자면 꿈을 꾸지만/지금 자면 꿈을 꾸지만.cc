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

int main()
{
    fio();

    int N, A, B; cin >> N >> A >> B;
    
    vector<int> T;

    FOR(i,N,0)
    {
        int x; cin >> x;
        T.push_back(x);
    }

    sort(all(T));

    // 과제를 완료하는 시간 A만큼 걸림 
    int ans = 0;

    // 잠을 자는 경우의 수 0 ~ A-1 을 고른다.
    int cnt = 0;
    int now = 0;
    int time = A;

    FOR(X, A, 0)
    {
        //언제 잠을 잘지를 고른다. : i번째 과제를 하기 전에 잠을 자고 시작을 한다는 의미이다. 근데 잠을 안자고 하는 경우도 있음
        FOR(i,T.size()+1,0)
        {
            cnt = 0;
            now = 0;
            time = A;

            //그때의 과제 수행 개수를 계산한다. i번째 과제 수행 전까지는 a만큼 시간이 걸리고, 그 이후는 A-X만큼 시간이 걸린다.
            FOR(j,T.size(),0)
            {
                //취침
                if(j == i)
                {
                    now += B*X;
                    time = A-X;
                }

                // 현재 확인하는 과제를 수행할 수 없는 경우 : 다음 과제를 트라이 한다.
                if(T[j] < (now + time)) continue;

                // 현재 확인하는 과제를 수행할 수 있는 경우
                cnt++;
                now += time;
            }

            // cout << "X : " << X << " i : " << i << "인 경우 : " << cnt << '\n';
            ans = max(ans, cnt);
        }

    }

    // 잠을 아예 안자는 경우?
    cnt = 0;
    now = 0;
    time = A;
    FOR(j, T.size(), 0)
    {
        // 현재 확인하는 과제를 수행할 수 없는 경우 : 다음 과제를 수행한다.
        if (T[j] < (now + time))
        {
            continue;
        }

        // 현재 확인하는 과제를 수행할 수 있는 경우
        cnt++;
        now += time;
    }
    ans = max(ans, cnt);

    cout << ans;
}