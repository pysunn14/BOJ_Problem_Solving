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

int x[101010], p[101010];

ll S[101010];
int mx_idx[101010];

int main()
{
    fio();

    int N; cin >> N;

    FOR(i, N + 1, 1)
    {
        cin >> x[i] >> p[i];
    }
    
    S[1] = p[1];
    FOR(i, N + 1, 2)
    {
        S[i] = S[i - 1] + p[i];
    }

    int mx = 0;
    mx_idx[1] = 1;
    FOR(i, N + 1, 2)
    {
        if(mx < p[i])
        {
            mx = p[i];
            mx_idx[i] = i;
        }

        else mx_idx[i] = mx_idx[i-1];
    }

    int idx = -1;
    int next = -1;
    FOR(i, N + 1 , 1)
    {
        if(S[i - 1] > x[i])
        {
            // 그냥 한번 건너뛰어서 되는지도 체크
            bool ok = true;
            FOR(j, N + 1, i + 1)
            {
                if(S[j - 1] - p[i] > x[j]) 
                {
                    ok = false;
                    break;
                }
            }

            if(ok)
            {
                cout << "Kkeo-eok";
                return 0;
            }

            idx = mx_idx[i - 1];
            next = i;
            break;
        }
    }
    
    if(idx == -1)
    {
        cout << "Kkeo-eok";
        return 0;
    }

    FOR(i, N + 1, next)
    {
        if(S[i-1] - p[idx] > x[i])
        {
            cout << "Zzz";
            return 0;
        }
    }   
    cout << "Kkeo-eok";
}