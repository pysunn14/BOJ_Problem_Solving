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
    ll one = 0;
    ll two = 0;

    int N; 
    cin >> N;

    int h[101010];

    ll sum = 0;

    FOR(i,N+1,1) 
    {
        int x; 
        cin >> x;
        one += x % 2;
        two += x / 2;
    }

    if(one > two) cout << "NO"; // 같으면 괜

    else 
    {
        if((two - one) % 3 == 0) cout << "YES";
        else cout << "NO";
    }
}

