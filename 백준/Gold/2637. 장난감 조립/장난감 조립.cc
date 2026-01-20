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

map<int,int> graph[101]; // 인접한 그래프 관계

bool check[101];
map<int,int> dp[101]; // 요구하는 모든 선행 부품 관계 
int indegree[101]; 

map<int,int> go(int i)
{
    // base
    map<int,int> res;
    if(!indegree[i])
    {
        check[i] = true;
        res[i] = 1;
        return res; 
    }

    // already 
    if(check[i]) return dp[i];

    for(const auto& [node, cnt] : graph[i]) 
    {
        map<int,int> child = go(node); 

        for(const auto& [basis, bcnt] : child)
        {
            res[basis] += cnt * bcnt;
        }
    }
    
    check[i] = true; // visit
    return dp[i] = res; 
}

int main()
{
    fio();

    int N; cin >> N; // N : 완제품 번호. 

    int M; cin >> M;
    
    for(int i = 1 ; i <= M ; i++) 
    {
        int X, Y, K; 
        cin >> X >> Y >> K; 
        indegree[X]++; 
        graph[X][Y] = K; 
    }
    
    map<int,int> res = go(N);
    
    // 기본부품 / 소요 개수 출력. 
    for(const auto& e : res) cout << e.first << ' ' << e.second << '\n';
}