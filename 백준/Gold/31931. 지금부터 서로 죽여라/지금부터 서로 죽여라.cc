#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define test(a) \
    int _;      \
    cin >> _;   \
    FOR(a, _, 0)
typedef long long ll;
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)
#define fio()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define weight first
#define vertex second
#define all(v) v.begin(), v.end()
#define mid (lo + hi) / 2
using namespace std;

#define NARUTO cout<<"NARUTO\n";
#define SASUKE cout<<"SASUKE\n";
#define DRAW cout<<"DRAW\n";

typedef struct
{
    ll HP;
    ll ATK;
    ll HEAL;
}Character;

int main()
{
    fio();

    test(T)
    {
        ll X, Y;
        cin >> X >> Y;
        ll A, B, C, D;
        cin >> A >> B >> C >> D;

        Character n = {X, A, B};
        Character s = {Y, C, D};

        ll n_turn = n.HP / s.ATK + (n.HP % s.ATK != 0);
        ll s_turn = s.HP / n.ATK + (s.HP % n.ATK != 0);

        // 1. 나루토가 바로 죽이는 경우
        if(s.HP <= n.ATK) NARUTO

        // 2. 둘다 힐량이 부족한 경우 : 무조건 빠르게 때리는 것이 이득임
        else if(n.HEAL < s.ATK && s.HEAL < n.ATK)
        {
            if(s_turn <= n_turn) NARUTO
            else SASUKE
        }

        // 3. 둘다 무한으로 힐할 수 있는 경우
        else if(n.HEAL >= s.ATK && s.HEAL >= n.ATK) DRAW

        // 4. 둘중 하나만 무한으로 힐할 수 있는 경우
        // 4-1. 나루토만 힐할 수 있는 경우
        else if(n.HEAL >= s.ATK && s.HEAL < n.ATK)
        {
            //나루토의 힐량이 사스케의 공격력보다 크다면
            if(n.HEAL > s.ATK) NARUTO

            //힐량이 같다면
            else
            {
                // 나루토가 먼저 사스케를 죽일 수 있는 상황이면 이긴다 : 다시 말해서 나루토가 빈사 상태에 이르기 전에 먼저 사스케를 죽일 수있는지를 확인한다.
                if(s_turn <= n_turn) NARUTO
                else DRAW
            }
        }
        
        // 4-2. 사스케만 힐할 수 있는 경우
        else
        {
            //사스케의 힐량이 나루토의 공격력보다 크다면
            if(s.HEAL > n.ATK)
            {
                SASUKE
            }
            
            //힐량이 같다면
            else
            {
                // 사스케가 먼저 나루토를 죽일 수 있다면
                if(s_turn > n_turn) SASUKE
                else DRAW
            }
        }
    }
}