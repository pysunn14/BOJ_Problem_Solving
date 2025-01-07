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

    int N, P; cin >> N >> P;

    string S; cin >> S;
    string T = ""; 

    T += '(';

    for(int i = 0 ; i < S.size() ; i++)
    {
        if(S[i] == '+') 
        {
            T += ')';
            T += '+';
            T += '(';
        }
        else if(S[i] == '(' || S[i] == ')') 
        {
            T += S[i];
            T += S[i];
        }
        else T += S[i];
    }
    T += ')';
    cout << T.size() << '\n' << T;   
}