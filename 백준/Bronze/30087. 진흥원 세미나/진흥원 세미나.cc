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

map<string,string> m;

int main()
{
    fio();
    
    m["CyberSecurity"]=	"B101";
    m["Network"]=	"303";
    m["Startup"]="501";
    m["TestStrategy"]=	"105";
    m["ArtificialIntelligence"]	="302";
    m["Algorithm"] = "204";
    m["DataAnalysis"] = "207";


    int n; cin>>n;

    FOR(i,n,0)
    {
        string s; cin >> s;

        cout << m[s] << '\n';
    }
}