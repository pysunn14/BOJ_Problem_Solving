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
        ordered_set OS;

        int k; cin>>k;

        FOR(i,k,0)
        {
            char op; 
            int n;
            cin>>op>>n;

            if(op == 'I') OS.insert(n);
            else if(op == 'D')
            {
                if(n == -1)
                {
                    m_erase(OS, *OS.find_by_order(0));
                }

                else
                {
                    m_erase(OS, *OS.find_by_order(OS.size()-1));
                }
            }
        }
        if(OS.empty()) cout<<"EMPTY\n";
        else
        {
            cout << *OS.find_by_order(OS.size()-1) << ' ' << *OS.find_by_order(0) << '\n';
        }
    }

    
}