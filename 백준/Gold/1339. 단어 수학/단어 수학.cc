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

    int N; cin >> N;
    set<char> alphabet;
    vector<string> words;

    map<char, int> m;

    FOR(i,N,0)
    {
        string word; cin >> word;
        words.push_back(word);
        FOR(j,word.size(),0) 
        {
            alphabet.insert(word[j]);
            m[word[j]] += pow(10,word.size()-j-1);
        }
    }

    vector<pii> v;
    FORE(e, m)
    {
        v.push_back({e.second, e.first});
    }

    sort(all(v));
    reverse(all(v));

    // 가중치가 많은 수 부터 9를 넣어주면 된다.

    map<char, int> value;

    int num = 9;
    FORE(e,v)
    {
        value[e.second] = num;
        num--;
    }

    int sum = 0;
    // 계산

    FORE(word, words)
    {
        string a = "";
        FORE(w, word) a += value[w] + '0';

        sum += stoi(a);
    }

    cout << sum;
}