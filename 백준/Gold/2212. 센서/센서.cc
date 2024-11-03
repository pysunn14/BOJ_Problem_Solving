#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define test(a) int _; cin >> _; FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

int main()
{
    fio();

    int N, K;
    cin >> N >> K;

    if(K > N) K = N;
    vector<int> diff;
    set<int> A;
    vector<int> sensor;

    FOR(i,N,0)
    {
        int x; cin >> x;
        if(A.find(x) != A.end()) continue;
        A.insert(x);
        sensor.push_back(x);
    } 
    sort(all(sensor));

    for(int i = 0 ; i < sensor.size()-1 ; i++)
    {
        diff.push_back(sensor[i+1] - sensor[i]);        
    }

    sort(all(diff));

    ll sum = 0;
    FOR(i, diff.size()-K+1,0) sum += diff[i];
    cout << sum;
}

