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
    int n; cin >> n;
    set<string> s;
    
    for(int i = 0 ; i < n ; i++)
    {
        string a,b; cin >> a >> b; 
        if(b == "enter") s.insert(a);
        else s.erase(a);
    }

    stack<string> ss;
    
    for(const auto& e : s) ss.push(e);

    while(!ss.empty())
    {
        string e = ss.top();
        ss.pop(); 
        cout << e << '\n'; 
    }
}