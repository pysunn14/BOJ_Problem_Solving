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
        int N; string P; cin >> N >> P;

        if(N == 1)
        {
            cout << "4 2"<<'\n';
            continue;
        }
        
        int sum = 0;
        for(int i = 0 ; i < N; i++)
        {
            sum += P[i] - '0';
        }

        int rem = sum % 3;
        int need = 3-rem;

        for(int i = 0 ; i < N; i++)
        {
            int now = P[i] - '0';
            
            string Q = P;
            int R = 3; 
            
            int UP = now + need;
            int DOWN = now - rem; 

            // 다른 숫자면 구간만 맞게 변경 
            if(UP <= 9) Q[i] = char(UP) + '0';
            else Q[i] = char(DOWN) + '0';

            cout << Q << ' ' << R << '\n';
        }
    }
}