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

    int n,m; cin >> n >> m;

    int A[101];

    FOR(i,n+1,1) A[i] = i;

    while(m--)
    {
        int i,j; cin >> i >> j;
        stack<int> st;
        for(int k = i ; k <= j; k++) st.push(A[k]);

        int up = i;
        while(!st.empty())
        {
            int top = st.top();
            st.pop();
            A[up] = top;
            up++;
        }
    }

    FOR(i,n+1,1) cout << A[i] << ' ';
}