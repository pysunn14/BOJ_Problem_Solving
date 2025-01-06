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

int A[10];
bool check[10];
map<pii, int> m;

set<pii> line;

int main()
{
    //변
    line.insert({1,3});
    line.insert({3,1});
    m[{1,3}] = 2;
    m[{3,1}] = 2;

    line.insert({3,9});
    line.insert({9,3});
    m[{3,9}] = 6;
    m[{9,3}] = 6;

    line.insert({9,7});
    line.insert({7,9});
    m[{9,7}] = 8;
    m[{7,9}] = 8;

    line.insert({7,1});
    line.insert({1,7});
    m[{7,1}] = 4;
    m[{1,7}] = 4;

    //중앙
    line.insert({2,8});
    line.insert({8,2});
    m[{2,8}] = 5;
    m[{8,2}] = 5;

    line.insert({6,4});
    line.insert({4,6});
    m[{6,4}] = 5;
    m[{4,6}] = 5;

    //대각선
    line.insert({1,9});
    line.insert({9,1});
    m[{1,9}] = 5;
    m[{9,1}] = 5;

    line.insert({7,3});
    line.insert({3,7});
    m[{7,3}] = 5;
    m[{3,7}] = 5;

    fio();
    int L; cin >> L;

    FOR(i,L+1,1) cin >> A[i];

    FOR(i,L+1,1)
    {
        if (check[A[i]])
        {
            cout << "NO";
            exit(0);
        }
        check[A[i]] = true;

        if(i == L) break;
        if(line.find({A[i], A[i+1]}) != line.end())
        {
            if(!check[m[{A[i],A[i+1]}]])
            {
                cout << "NO";
                exit(0);
            }
        }
    }
    cout << "YES";
}