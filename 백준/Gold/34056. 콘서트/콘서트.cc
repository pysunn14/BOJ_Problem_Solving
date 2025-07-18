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

ll D[202020];

int main()
{
    fio();

    int N; cin >> N;

    FOR(i,N+1,1) cin >> D[i];

    int Q; 
    cin >> Q;

    while (Q--)
    {
        int cmd; 
        cin >> cmd;

        if(cmd == 1)
        {
            ll c, x; 
            cin >> c >> x;    
            
            ll rem = x;

            for(int i = c ; i >= 1 && rem > 0; i--)
            {
                ll cap = min(D[i], rem);
                rem -= cap;
                D[i] += cap;
            }

            rem = x;

            for(int i = c+1 ; i <= N  && rem > 0; i++)
            {
                ll cap = min(D[i], rem);
                rem -= cap;
                D[i] += cap;
            }
        }

        else 
        {
            int c; 
            cin >> c;
            cout << D[c] << '\n';
        }
    }
}