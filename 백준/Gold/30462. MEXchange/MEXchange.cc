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

ll A[202020];
ll B[202020];

int main()
{
    fio();

    int N; cin >> N;
    FOR(i,N+1,1) cin >> B[i];
    
    bool ok = true;

    // test 

    // 0. last == N + 1
    if(B[N] != N + 1) ok = false;

    // 1. asc
    FOR(i,N,1)
    {
        if(B[i] > B[i + 1]) ok = false;
    }

    // 2. valid
    FOR(i,N+1,1)
    {
        if(i + 1 < B[i])
        {
            ok = false;
        }
    }

    int Num[202020];
    FOR(i,N+1,1) Num[i] = i;
    
    // 3. 나머지면 가능할듯한데 
    // 처음으로 2나오는 곳에 1 할당하기 
    FOR(i,N+1,1)
    {
        if(B[i] == 2)
        {
            A[i] = 1;
            Num[1] = 0;
            break;
        }
    }
    
    for(int i = N ; i >= 2; i--)
    {
        if(!A[i])
        {
            if(B[i] != B[i-1])
            {
                A[i] = B[i-1];
                Num[B[i-1]] = 0;
            }
        }
    }

    int idx = 1;
    // 나머지는 아직 안쓴거 대충 자유롭게 채워주기. 
    FOR(i,N+1,1)
    {
        if(!A[i])
        {
            while (!Num[idx]) idx++;
            A[i] = Num[idx];
            Num[idx] = 0;
        }
    }
    cout << '\n';
    
    if(ok)
    {
        cout << "Yes\n";
        FOR(i,N+1,1) cout << A[i] << ' ';
    }

    else cout << "No\n";
}