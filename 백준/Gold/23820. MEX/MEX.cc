#include <bits/stdc++.h>
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
using namespace std;

int seoroso[2000004];
void seive(int n, vector<int> &a)
{
    for (int i = 0; i < n; i++)
    {
        if(i!=n-1 && a[i]==a[i+1]) continue;
        for (int j = 0; j < n; j++)
        {
            if(j!=n-1 && a[j]==a[j+1]) continue;
            if(a[i] * a[j] >= 2000003) break;
            seoroso[a[i] * a[j]] = 1;
        }
    }
    
    FOR(i,2000004,0)
    {
        if(!seoroso[i])
        {
            cout << i;
            exit(0);
        }
    }
}

int main()
{
    fio();

    int n; cin >> n;
    vector<int> a(n); 
    
    FOR(i,n,0) cin >> a[i];
    sort(all(a));
    
    seive(n, a);
}