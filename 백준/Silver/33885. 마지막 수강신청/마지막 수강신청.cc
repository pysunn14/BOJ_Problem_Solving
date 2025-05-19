#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
#define all(v) v.begin(), b.end()

#define pii pair<int,int>
using namespace std;

#define FOR(a,b,c) for(int a=c ; a<b ; a++)

int c[11]; // 학점 

vector<pii> item[11];

map<string, int> m;

int main()
{
    fio();
    
    m["MON"] = 1;
    m["TUE"] = 2;
    m["WED"] = 3;
    m["THU"] = 4;
    m["FRI"] = 5;

    int N,M; cin >> N >> M;

    FOR(i,N+1,1)
    {
        // c :: 학점  s : 횟수  d h 
        cin >> c[i]; 
        int s; 
        cin >> s;
        
        FOR(j,s+1,1) 
        {
            string yo; cin >> yo; int h; cin >> h;
            item[i].push_back({m[yo], h});
        }
    }

    // 처음부터 끝까지 모든 경우의수를 세면서, 
    // N개의 순열이 있고 이를 순열로 세서 쓸때랑 안쓸때로 해서 체크해야되는? 
    int ans = 0;

    int k = 0;
    while (k <= (1<<N)) 
    {
        int loc = 0;

        bool select[11] = {false};
        // 그렇게 선택을 했을 때, 가능 하냐? 겹치지 않냐? 

        string now = "";
        
        for(int i = 1 ; i <= N; i++) 
        {
            if(((k >> (i-1)) & 1 ) == 1)
            {
                select[i] = true;
                loc += c[i];
            }
        }

        bool ok = true;

        // 만약 겹치고 있다면 check 
        FOR(i,N+1,1)
        {
            if(select[i])
            {
                // 가지고 있는 아이템들이, 다른 select한 아이템들 중에 겹치는게 있음 
                for(auto [a, b] : item[i])
                {
                    FOR(j,N+1,1)
                    {
                        if(i == j || !select[j]) continue;

                        for(auto [c, d] : item[j])
                        {
                            if(a == c && b == d)
                            {
                                ok = false;
                                break;
                            }
                        } 
                    }
                }
            }
        }

        // 겹치지 않는다면 정답 후보로 업데이트 
        if(ok) ans = max(ans, loc); 
        k++; 
    }
    
    if(ans >= M) cout << "YES";
    else cout << "NO";
}