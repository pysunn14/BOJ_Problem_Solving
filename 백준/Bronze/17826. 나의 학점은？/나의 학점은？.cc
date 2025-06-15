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

    int score[50];

    FOR(i,50,0) cin >> score[i];

    int a; cin >> a;
    int idx = 0;

    FOR(i,50,0)
    {
        if(score[i] == a)
        {
            idx = i+1;
            break;
        }
    }

    if(idx <= 5) cout << "A+";
    else if(idx <= 15) cout << "A0";
    else if(idx <= 30) cout << "B+";
    else if(idx <= 35) cout << "B0";
    else if(idx <= 45) cout << "C+";
    else if(idx <= 48) cout << "C0";
    else cout << "F";
}