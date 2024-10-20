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

vector<int> arr;
int divide_and_conquer(int lo, int hi)
{
    // 더 이상 분할할 수 없는 경우
    if (lo >= hi) return arr[lo];

    int result = INT_MIN;

    // 부분합의 최대값이 mid를 포함하여 걸치는 상황 - Crossing Mid MaxSum 
    int left = INT_MIN+1;
    int right = INT_MIN+1;

    int left_sum = 0;

    for(int i = mid ; i >= lo; i--)
    {
        left_sum += arr[i];
        if(left_sum > left) left = left_sum;
    }

    int right_sum = 0;

    for(int j = mid+1; j <= hi; j++)
    {
        right_sum += arr[j];
        if(right_sum > right) right = right_sum;
    }

    // 부분합이 mid를 기준으로 한 쪽에 생기는 상황도 두 개 있다.
    result = max({left + right, divide_and_conquer(lo, mid), divide_and_conquer(mid+1, hi)});
    // 결과는 이 세개의 경우 중 가장 큰 경우이다.
    return result;
}

int main()
{
    fio();

    int N; 
    cin >> N;
    arr.push_back(0);

    FOR(i,N+1,1) 
    {
        int x; cin >> x;
        arr.push_back(x);
    }
    cout << divide_and_conquer(1, N);
}