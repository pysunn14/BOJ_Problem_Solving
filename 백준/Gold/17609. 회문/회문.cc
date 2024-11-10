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
    test(T)
    {
        string s; cin >> s;
        int i = 0;
        int j = s.size() - 1;
        int type1 = 0;
        
        while (i <= j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }

            else
            {
                if(!type1)
                {
                    type1++;
                    if(s[i] == s[j-1]) j--;
                    else 
                    {
                        type1++;
                        break;
                    }
                }

                else if(type1 == 1)
                {
                    type1++;
                    break;
                }
            }
        }

        i = 0;
        j = s.size()-1;
        int type2 = 0;

        while (i <= j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }

            else
            {
                if(!type2)
                {
                    type2++;
                    if(s[i+1] == s[j]) i++;
                    else 
                    {
                        type2++;
                        break;
                    }
                }

                else if(type2 == 1)
                {
                    type2++;
                    break;
                }
            }
        }

        cout << min(type1,type2) << '\n';
    }
}