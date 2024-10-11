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

    string s; cin >> s;

    string interger_part = "";
    string decimal_part = "";
    string circular_part ="";

    int ccount = 0;

    int i = 0;
    for( ; i < s.size() ; i++)
    {
        if(s[i] == '.')
        {
            i++;
            break;
        }
        interger_part += s[i];
    }

    for(; i <s.size() ; i++)
    {
        if(s[i] == '(')
        {
            i++;
            while (i < s.size() && s[i] != ')')
            {
                if(s[i] == ')') 
                {
                    break;
                }
                circular_part += s[i];
                i++;
            }
        }
        else decimal_part += s[i];
    }

    
    ll a, b, c;

    if(decimal_part.size() + circular_part.size() == 0)
    {
        cout << interger_part << '/' << 1;
        return 0;
    }

    else if(circular_part.size() == 0)
    {
        string zero = "1"; FOR(i,decimal_part.size(),0) zero += '0';
        a = (ll)stoi(interger_part+decimal_part); 
        b = (ll)stoi(zero);
    }

    else
    {
        string nine = ""; FOR(i,circular_part.size(),0) nine += '9';
        string zero = ""; FOR(i,decimal_part.size(),0) zero += '0';
        a = ((ll)stoi(interger_part+decimal_part))*(ll)stoi(nine) + (ll)stoi(circular_part);
        b = (ll)stoi(nine+zero);
    }


    c = __gcd(a,b);
    cout << a/c << '/' << b/c;
}