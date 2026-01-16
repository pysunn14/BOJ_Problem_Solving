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

    int N,M; cin >> N >> M;
    
    int A[101];

    int tmp = 0;
    
    for(int i = 1 ; i <= N ; i++) A[i] = i; 
    
    for(int i = 0 ; i < M ; i++)
    {
        int a, b; cin >> a >> b;     

        tmp = A[a];
        A[a] = A[b];
        A[b] = tmp;
    }

    for(int i = 1 ; i <= N ; i++) cout << A[i] << ' '; 
}