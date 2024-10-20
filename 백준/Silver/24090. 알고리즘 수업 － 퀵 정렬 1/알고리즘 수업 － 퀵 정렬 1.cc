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

int A[10001];
ll cnt;
int a,b;
int K;

void swap(int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int partition(int p, int r)
{
    int pivot = A[r];

    int i = p - 1;

    for(int j = p ; j <= r - 1; j++)
    {
        if(A[j] <= pivot)
        {
            i++;
            swap(i,j);
            cnt++;
            if(cnt == K)
            {
                a = A[i];
                b = A[j];
            }
        } 
    }

    // j 위치와 r위치를 서로 바꾼다.
    if(i + 1 != r)
    {
        swap(i + 1, r);
        cnt++;
        if (cnt == K)
        {
            a = A[i + 1];
            b = A[r];
        }
    }
    return i+1;
}

void quicksort(int p, int r)
{
    if(p >= r) return;
    int q = partition(p,r);
    quicksort(p,q-1);
    quicksort(q+1,r);
}
 
int main()
{
    fio();

    int N;

    cin >> N >> K;

    FOR(i,N+1,1) cin >> A[i];

    quicksort(1,N);

    if(cnt < K) cout << -1;
    else cout << a << ' ' << b;
}