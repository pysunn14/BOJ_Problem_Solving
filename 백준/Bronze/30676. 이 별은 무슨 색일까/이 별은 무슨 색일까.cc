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

    int L; cin >> L;

    if(L < 425) cout << "Violet";
    else if(L < 450) cout << "Indigo";
    else if(L < 495) cout << "Blue";
    else if(L < 570) cout << "Green";
    else if(L < 590) cout << "Yellow";
    else if(L < 620) cout << "Orange";
    else if(L <= 780) cout << "Red";
}