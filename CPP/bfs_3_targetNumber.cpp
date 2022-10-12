#include <string>
#include <vector>
#include <queue>

using namespace std;

struct num{
    int value, index;
};
queue<struct num> q;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int length = numbers.size();
    
    q.push({numbers[0], 0});
    q.push({-1*numbers[0], 0});
    
    while(!q.empty()){
        struct num c = q.front();
        q.pop();
        
        if(c.index == length-1){
            if(c.value == target){
                answer++;
            }
            continue;
        }

        int ni = c.index+1;
        int nv1 = c.value + numbers[ni];
        int nv2 = c.value - numbers[ni];
        q.push({nv1, ni});
        q.push({nv2, ni});
    }
    
    return answer;
}

/*
https://school.programmers.co.kr/learn/courses/30/lessons/43165
테스트 1 〉	통과 (19.19ms, 11.4MB)
테스트 2 〉	통과 (18.98ms, 11.5MB)
테스트 3 〉	통과 (0.03ms, 3.67MB)
테스트 4 〉	통과 (0.08ms, 4.1MB)
테스트 5 〉	통과 (0.62ms, 4.1MB)
테스트 6 〉	통과 (0.06ms, 4.09MB)
테스트 7 〉	통과 (0.02ms, 4.1MB)
테스트 8 〉	통과 (0.15ms, 4.17MB)
*/
