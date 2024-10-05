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

    int N; 
    cin >> N;

    int A[202020];
    FOR(i,N+1,1) cin>>A[i];
    
    ll cnt = 0;
    stack<int> s;

    s.push(A[1]);

    FOR(i,N+1,2)
    {
        if(s.top() > A[i])
        {
            s.push(A[i]);
            cnt++;
        }

        else 
        {
            while (!s.empty() && s.top() < A[i]) 
            {
                s.pop();
                cnt++; // ?
            }
            s.push(A[i]);   
            if(s.size() > 1) cnt++;
        }
    }

    cout << cnt;
}