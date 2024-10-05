#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pii pair<double,double>
#define test(a) int _; cin >> _; FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

int N; 
int main()
{
    fio();

    test(t)
    {
        cin >> N;
        vector<pii> p;
        vector<bool> permu;

        FOR(i,N,0) if(i%2 == 0) permu.push_back(0); else permu.push_back(1);

        FOR(i,N,0)
        {
            // 점은 한번씩 쓰인다.
            int a,b; cin >> a >> b;
            p.push_back({a,b});
        }

        // brute forcing
        double ans = 1e10;

        do
        {
            double now = 0;
            pii vec_sum = {0,0};

            for(int i = 0 ; i < N; i++)
            {
                pii vec = p[i];
                if(permu[i])
                {
                    vec_sum.first += vec.first;
                    vec_sum.second += vec.second;
                }
                else
                {
                    vec_sum.first -= vec.first;
                    vec_sum.second -= vec.second;        
                }
            }

            now = sqrt((vec_sum.first)*(vec_sum.first)+(vec_sum.second)*(vec_sum.second));
            ans = min(ans, now);

        } while (next_permutation(all(permu)));

        cout << fixed << setprecision(7) << ans << '\n';
    }
}