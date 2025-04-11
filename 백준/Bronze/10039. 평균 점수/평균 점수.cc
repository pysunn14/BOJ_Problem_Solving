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

    vector<int> v(5);

    FOR(i, 5, 0) 
    {
        cin >> v[i];
        v[i] = max(40, v[i]);
    }

    double sum = accumulate(all(v), 0);
    double avg = sum / 5;
    cout << avg << "\n";
}