#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define test(a) \
    int _;      \
    cin >> _;   \
    FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define weight first
#define vertex second
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

int main()
{
    //

    int N; cin>>N;

    string now = "666";
    int num = 666;

    int i = 0;
    while (true)
    {
        now = to_string(num);
        // 6이 3연속이면 추가 
        for(int j = 0 ; j < now.size() - 2 ; j++)
        {
            if(now[j] == '6' && now[j+1] == '6' && now[j+2] == '6')
            {
                i++;
                break;
            }
        }

        if(i == N)
        {
            cout << num;
            return 0;
        }
        
        num++;
    }
}
