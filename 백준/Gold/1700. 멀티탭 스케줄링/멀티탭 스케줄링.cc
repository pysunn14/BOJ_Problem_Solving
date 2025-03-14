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

    int N, K; cin >> N >> K;

    int A[101];

    FOR(i,K+1,1) cin >> A[i];

    set<int> s;

    ll ans = 0;

    FOR(i,K+1,1) 
    {
        // 구멍이 꽉 찬 경우
        if(s.size() == N)
        {
            // 아직 없는 원소 : 어떤 원소를 덜어야 함.
            if(s.find(A[i]) == s.end())
            {
                ans++;
                // set 에서 하나를 뽑고 현재 원소를 넣는다. 어떤 원소를 뽑을까? 
    
                // 현재 있는 셋 중에서, 이후동안 가장 오랫동안 등장하지 않게 되는 원소를 고른다. 
                map<int,int> m;
                FORE(e, s)
                {
                    m[e] = 1e9;
    
                    FOR(j,K+1,i+1)
                    {
                        // 각 원소가 처음으로 등장하는 인덱스 저장 (디폴트는 1억)
                        if(A[j] == e)
                        {
                            m[e] = j;
                            break;
                        }
                    }
                }

                // 인덱스가 가장 큰 원소를 지우기
                int mx = 0;
                int del;
                FORE(e, s)
                {
                    if (m[e] > mx)
                    {
                        mx = m[e];
                        del = e;
                    }
                }
                s.erase(del);
                s.insert(A[i]);
            }
            
            // 있는 원소 : sktip
            else continue;
        }
        
        // 구멍이 아직 안 찬 경우 : 그냥 넣기
        else 
        {
            if(s.find(A[i]) == s.end()) s.insert(A[i]);
            else continue;
        }
    }

    cout << ans;
}