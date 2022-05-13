#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 완주하지 못한 선수
// https://programmers.co.kr/learn/courses/30/lessons/42576
string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    int i;
    for(i=0;i<completion.size();i++){
        if(completion[i]!=participant[i]){
            break;
        }
    }
    
    string answer = participant[i];
    return answer;
}
