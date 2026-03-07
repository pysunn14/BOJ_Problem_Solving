#include <bits/stdc++.h>

#define fio(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int solution(vector<vector<int>> signals) {
    
    int answer = -2;
    
    int n = 0;
    for(auto signal : signals) n++;
    
    int state[6]; 
    int rem[6]; 
    
    for(int i = 0 ; i < n; i++) state[i] = 0; // G Y R : 0 1 2
    for(int i = 0 ; i < n; i++) rem[i] = signals[i][0]; 
    
    int time = 0;
    
    while(time < 10000000)
    {   
        time++;
        
        for(int i = 0 ; i < n ; i++)
        {   
            rem[i]--; 
            
            if(rem[i] > 0) continue;
            
            // 시간이 없어요 - 상태가 변화했다는 뜻임. 
            else
            {
                // 상태변화 
                state[i]++; 
                state[i] = state[i] % 3; 
                rem[i] = signals[i][state[i]]; //새롭게 갱신하기 
            }
        }   
        
        bool check = true;
        for(int i = 0 ; i < n ; i++) if(state[i] != 1) check = false;
        
        if(check) 
        {
            answer = time;
            break;
        }
    }
    
    return answer + 1;
}