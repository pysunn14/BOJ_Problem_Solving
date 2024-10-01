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

    int N,K; 
    cin >> N >> K;
    string s; 
    cin >> s;

    stack<int> stk;
    stk.push(s[0]-'0');

    // 숫자 K개를 지웠다면 남은 수는 N-K개이다.
    int removed = 0;

    // 만약 남아있는 문자열의 개수 (N)
    for(int i = 1 ; i < N; i++)
    {
        int top = stk.top();
        int now = s[i] - '0';

        if(removed >= K || top >= now) stk.push(now);

        //나보다 작은 것이 있다면 계속 제거해나감
        else 
        {
            while (!stk.empty())
            {
                if(stk.top() >= now || removed >= K) break;
                stk.pop();
                removed++;
            }
            stk.push(now);
        }
    }

    vector<int> ans;
    while (!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }
    
    reverse(all(ans));
    for(int i = 0 ; i < N-K; i++) cout << ans[i];
}