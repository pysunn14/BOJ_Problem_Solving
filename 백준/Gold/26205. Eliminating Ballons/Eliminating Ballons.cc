#include <bits/stdc++.h>

using namespace std;

int A[1010101]; 

int main()
{
    int n; cin >> n;

    int H[505050];

    for(int i = 1 ; i <= n; i++) cin >> H[i];

    A[H[1]] = 1;

    for(int i = 2 ; i <= n; i++) 
    {
        if(A[H[i] + 1] > 0)
        {
            A[H[i] + 1]--; 
            A[H[i]]++;
        }
        else A[H[i]]++;
    }

    long long ans = 0;
    
    for(int i = 1 ; i <= 1000000; i++) ans += A[i];

    cout << ans;          

}