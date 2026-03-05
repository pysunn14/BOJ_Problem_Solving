#include <bits/stdc++.h>

using namespace std;

long long A[101010];
int N, M; 

bool check(long long C)
{
    int cnt = 1;
    bool ok = true;
    long long sum = A[1];

    if(A[1] > C) return false;
    
    for(int i = 2 ; i <= N ; i++)
    {
        sum += A[i];

        if(sum > C)    
        {
            cnt++; 
            sum = A[i];
            if(sum > C) return false;
            if(cnt > M) ok = false; 
        }
    }
    return ok;
}

int main()
{
    cin >> N >> M;

    for(int i = 1 ; i <= N ; i++) cin >> A[i];

    long long ans;

    long long lo = 0, hi = 1e9+1;

    while(lo + 1 < hi)
    {
        long long mid = (lo + hi) / 2LL;
        
        if(!check(mid)) lo = mid;
        else hi = mid;
    }

    if(check(lo)) ans = lo;
    else ans = hi;
    cout << ans;
} 