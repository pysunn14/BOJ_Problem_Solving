#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
    bool ok = true;

    string s;
    cin>>s;

    // a문자부터 z문자까지 등장하는 위치 (그 index)를 저장한다.
    // 이제 각 pos의 위치가 L,R이라고 할 때, L-R-1이 반드시 짝수여야 한다.
    // 어떤 문자가 세 번 이상 등장한다면 반드시 불가능한 경우가 된다.
    vector<int> pos[26];

    FOR(i,s.size(),0)
    {
        pos[s[i]-'a'].push_back(i);
    }

    FORE(p, pos)
    {
        if(p.size() >= 3)
        {
            ok = false;
            break;
        }

        else if(p.size() == 2)
        {
            if((p[1] - p[0] - 1) % 2 == 1)
            {
                ok = false;
                break;
            }
        }
    }

    if(ok) cout<<"YES";
    else cout<<"NO";
}