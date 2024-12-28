#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

// 약수 가능 집합 : 약수로 등장한 횟수가 M번과 동일해야한다.
map<ll,ll> mp;

void factor(ll n)
{
    for(int i = 1 ; i * i <= n ; i++)
    {
        if(i * i == n) mp[i]++;
        else if(n % i == 0)
        {
            mp[i]++;
            mp[n/i]++;
        }
    }
}

int main()
{
    fio();

    int D, M;
    cin >> D >> M;

    vector<ll> d(D);
    for (int i = 0; i < D; i++) cin >> d[i];

    vector<ll> m(M);
    for (int i = 0; i < M; i++) cin >> m[i];

    // 약수 집합을 먼저 구한다음에 그다음에 배수 집합을 구해주면 된다.
    for(int i = 0 ; i < M; i++) factor(m[i]);

    set<ll> common_factor;
    for(auto p : mp) if(p.second >= M) common_factor.insert(p.first);

    set<int> ok;
    // 다 돌렸으면 맵을 확인하면서 M개 이상인 것에 대해서 배수 체크를 진행한다.
    // 모든 D의 집합에 대해서 배수 여야된다. 
    for(auto c : common_factor) 
    {
        bool yes = true;
        for(int i = 0 ; i < D ; i++)
        {
            //모든 d의 요소에 대해서 c는 배수여야 한다.
            if(c < d[i] || c % d[i] > 0) yes = false;
        }
        if(yes) ok.insert(c);
    }

    cout << ok.size();
    // d에 들어 있는 모든 수들의 배수이면서, m에 있는 모든 수의 약수여야 한다.
    // 그러면 보통 약수의 집합을 구하는게 낫지. m에서 첫번째 친구의 약수를 전부 구해주고,
}