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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

void m_erase(ordered_set &OS, int val)
{
    int index = OS.order_of_key(val);
    auto it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}

int main()
{
    fio();
    
    test(T)
    {
        int M; cin >> M;
        
        ordered_set OS;
        
        cout << M / 2 + 1 << '\n';

        int line = 0;

        FOR(i,M+1,1)
        {
            int x; cin >> x;
            OS.insert(x);

            if(i % 2 == 1) 
            {
                cout << *OS.find_by_order(OS.size() / 2) << ' ';
                line++;

                if(line == 10) cout << '\n';
            }
        }

        cout << '\n';
    }
}