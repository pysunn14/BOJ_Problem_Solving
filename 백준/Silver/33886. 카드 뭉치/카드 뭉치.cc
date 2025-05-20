#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
#define all(v) v.begin(), b.end()

#define pii pair<int,int>
using namespace std;

#define FOR(a,b,c) for(int a=c ; a<b ; a++)

int D[3030];
int DD[3030];
int A[3030];

int main()
{
    fio();

    int N; cin >> N;
    
    FOR(i,N+1,1) cin >> A[i];

    FOR(i,N+1,1) 
    {
        DD[i] = INT_MAX;
        D[i] = INT_MAX; 
    }

    DD[1] = 1;
    
    FOR(i, min(A[1] + 1, N + 1), 1) D[i] = 1;
    
    // D : 연결한 상태

    // DD : 새로 만든 상태 
    
    FOR(i, N+1, 2) 
    {
        int mn = INT_MAX;
        // 새로 만든다고 가정하기 - 연결되는 것 중 가장 최소로 
        for(int j = i - 1 ; j >= 1 ; j--) if(j + A[j] >= i) mn = min(mn, DD[j] + 1);
        
        // 새로 만든 상태 
        DD[i] = mn;
        
        // 지금 새로 만들었다고 쳤을때 닿는 부분을 모두 수정 (연결) 
        for(int j = i + 1 ; j <= min(i + A[i] - 1, N + 1) ; j++) D[j] = min(D[j], DD[i]);
    } 
    
    cout << min(DD[N], D[N]); 
}