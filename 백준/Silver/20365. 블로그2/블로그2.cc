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

    // B를 먼저할때랑 R을 먼저할 때중에 비교해서 출력하기 

    int B = 0;
    int R = 0 ;

    int n; cin >> n;
    string s; cin >> s;

    int i = 0;

    while(i < n)
    {
        if(s[i] == 'B')
        {
            B++;
            while(s[i] == 'B' && i < n)
            {
                i++;       
            }
        }
        
        else 
        {   
            R++;
            while(s[i] == 'R' && i < n)
            {
                i++;
            }
        }
    }

    cout << min(B, R) + 1;
}