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

int A[1010101]; 
int N,K; 

set<int> possible;

int main()
{
    fio();
    cin >> N >> K;
    FOR(i,N,0) cin >> A[i];

    int a = 0;
    possible.insert(a);

    a = (a + K) % N;
    for( ; a != 0 ; a = (a + K) % N) possible.insert(a);

    //각 원소에 대해서, 그 원소가 0 기준으로 가능한 자리에 있는지를 파악
    FOR(i,N,0)
    {
        if(possible.find(abs(i - A[i])) == possible.end()) 
        {
            cout << "NO";
            return 0;
        }
    }
    
    cout << "YES";
    return 0;
}

/*

각 숫자가 K씩 움직여서 갈 수 있는 곳에 존재하는지를 확인한다. 예를들어서

N=5, K=3일때
0은 3, 1, 4, 2, 0 으로 갈 수 있음.

    3 6 9 12 15

N=5, K=2 일때
0은 2, 4, 1, 3, 0 으로 갈 수 있음.

N=4, K=2 일때
0은 2,0만 갈수있음.



1 3 0 2 4

2 3 0 1 4

0 3 2 1 4

0 1 2 3 4

*/