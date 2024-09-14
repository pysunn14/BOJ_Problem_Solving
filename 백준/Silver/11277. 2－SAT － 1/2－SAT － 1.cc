#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define test(a) int _; cin >> _; FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define weight first
#define vertex second
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

bool x[21];
int main()
{
    fio();
    int N, M; 
    cin >> N >> M;
    vector<pii> clauses;
    bool ok = false;

    FOR(_,M,0)
    {
        int i,j; 
        cin >> i >> j;
        clauses.push_back({i,j});
    }

    unsigned int v= 0;
    FOR(v,pow(2,N)+1,0)
    {
        bool clause_check = true;
        FOR(i,N+1,1) x[i] = (v >> (i-1)) & 1;

        //clause check
        FORE(clause, clauses)
        {
            bool now = false;
            int a = clause.first, b = clause.second;

            // 현재 절이 참인지 판정한다
            if(a > 0 && b > 0)
            {
                if(x[a] || x[b])
                {
                    now = true;
                }
            }

            else if(a > 0 && b < 0)
            {
                if(x[a] || !x[-b])
                {
                    now = true;
                }
            }

            else if(a < 0 && b > 0)
            {
                if(!x[-a] || x[b])
                {
                    now = true;
                }
            }

            else
            {
                if(!x[-a] || !x[-b])
                {
                    now = true;
                }
            }
            clause_check &= now;
        }
        ok |= clause_check;
        if(ok) break;
    }
    cout << ok;
}