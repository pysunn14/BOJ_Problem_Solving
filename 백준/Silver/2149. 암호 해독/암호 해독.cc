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

char A[100][100];
char B[100][100];

int main()
{
    fio();

    string key, s;
    cin>>key>>s;

    int col = key.size();
    int row = s.size() / key.size();

    vector<char> sorted_key;

    FOR(i,col,0) sorted_key.push_back(key[i]);
    sort(all(sorted_key));

    int k = 0;
    FOR(j,col,0)
    {
        FOR(i,row,0)
        {
            A[i][j] = s[k++];
        }
    }

    bool vis[10] = {0};

    //decode
    FOR(i,col,0)
    {
        //now가 기존 key에서 몇 번째 순서 였는지를 확인한다.
        FOR(j, col, 0)
        {
            if(!vis[j] && key[j] == sorted_key[i])
            {
                // B행렬에 행단위로 전부 다 넣어준다.
                FOR(l,row,0) B[l][j] = A[l][i];
                vis[j] = true;
                break;
            }
        }
    }

    //output
    FOR(i,row,0) FOR(j,col,0) cout<<B[i][j];
}