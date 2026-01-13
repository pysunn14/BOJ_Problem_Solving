#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std; 

int main()
{
    int N; cin >> N;

    int a[4] = {0};

    int ans1 = 0;
    int ans2 = 0;

    for(int i = 0 ; i < 3*N; i++) 
    {
        int x; cin >> x;

        a[x]++;

        if(a[x] > N) 
        {
            ans1 = x;
        }
    }
    
    // 혼자 N-1개인거 
    for(int i = 1 ; i<= 3; i++)
    {
        if(a[i] == N-1)
        {
            ans2 = i;
            break;
        }
    }
    
    cout << ans2 << '\n'<<ans1<<'\n'; 
    return 0;
}