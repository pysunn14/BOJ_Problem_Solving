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

const int N = 1000000;
const int sz = 1010101;

int tree[sz * 4];

ll f(ll a, ll b)
{
    return a + b;
}

int query(int lo, int hi, int node, int left, int right)
{
    if (left > hi || right < lo) return 0;
    if (left <= lo && hi <= right) return tree[node];
    return f(query(lo, mid, node * 2, left, right), query(mid + 1, hi, node * 2 + 1, left, right));
}

// 얘만 하면 끝남
int find(int k)
{
    // 현재 보고 있는 노드가 k번째 인지를 확인을 해야한다.
    // 1번부터 현재 노드까지의 누적합을 알고 있으니까, 그 합은 지금 노드가 몇번째 위치인지를 말해준다.
    int ans;
    int lo = 0, hi = 1000001;
    while (lo + 1 < hi)
    {
        int now = query(1,N,1,mid,mid);
        int cur = query(1,N,1,1,mid);

        //개수가 k 이상이라는 것은, 정답에 포함가능한 후보이니까 일단 정답을 갱신함
        //이후 더 나은 최적해를 탐색함
        if(cur >= k) 
        {
            ans = mid;
            hi = mid;
        }
        else lo = mid;
    }

    return ans;
}

void update(int lo, int hi, int node, int idx, ll value)
{
    if (idx < lo || idx > hi) return;
    if (lo == hi)
    {
        tree[node] += value;
        return;
    }
    update(lo, mid, node * 2, idx, value);
    update(mid + 1, hi, node * 2 + 1, idx, value);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
}

int main()
{
    fio();

    int n; cin>>n;

    FOR(i,n,0)
    {
        int A,B,C;
        cin>>A;

        if(A == 1)
        {
            cin >> B;
            // B번째 사탕을 한 개 꺼낸다.
            int idx = find(B);
            update(1,N,1,idx,-1);
            cout << idx << '\n';
        }

        else
        {
            cin >> B >> C;
            update(1,N,1,B,C);
        }
    }
}