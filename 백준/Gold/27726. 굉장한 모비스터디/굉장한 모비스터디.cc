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

int parent[101010];
int code[3][101010];
int N;

void init_parent()
{
    FOR(i,101010,0) parent[i] = i;
}

int find(int x)
{
    if(x == parent[x]) return x; 
    return parent[x] = find(parent[x]);
}

void pushCode(int t)
{
    FOR(i,N+1,1)
    {
        code[t][i] = find(i);
    }
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if(a != b)
    {
        if(a < b) parent[b] = a;
        else parent[a] = b;
    }
}

int main()
{
    fio();

    cin >> N;
    int M1, M2, M3; 

    cin >> M1 >> M2 >> M3;

    init_parent();
    FOR(i, M1, 0)
    {
        int a,b; 
        cin >> a >> b;
        merge(a,b);
    }
    pushCode(0);

    init_parent();
    FOR(i, M2, 0)
    {
        int a,b; cin >> a >> b;
        merge(a,b);
    }
    pushCode(1);

    init_parent();
    FOR(i, M3, 0)
    {
        int a,b; cin >> a >> b;
        merge(a,b);
    }
    pushCode(2);

    map<vector<int>, vector<int>> m;
    FOR(i,N+1,1)
    {
        vector<int> v;

        FOR(t,3,0)
        {
            v.push_back(code[t][i]);
        }

        m[v].push_back(i);
    }

    int size = 0;
    FORE(mm, m)
    {
        vector<int> s = mm.second;
        if(s.size() < 2) continue;
        size++;
    }

    cout << size << '\n';

    vector<vector<int>> a;

    int i = 0;
    FORE(mm, m)
    {
        vector<int> s = mm.second;
        if(s.size() < 2) continue;
        vector<int> emp;
        a.push_back(emp);
        FORE(e, s)
        {
            a[i].push_back(e);
        }
        i++;
    }

    sort(all(a),[]( vector<int> x, vector<int> y){ return x[0] < y[0]; } );

    FORE(s, a)
    {
        FORE(e, s)
        {
            cout << e << ' ';
        }
        cout << '\n';
    }
    
}