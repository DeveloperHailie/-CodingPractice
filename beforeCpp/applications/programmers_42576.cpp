#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 완주하지 못한 선수
// https://programmers.co.kr/learn/courses/30/lessons/42576

// vector sort후 비교
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

// map을 이용. 
string solution2(vector<string> participant, vector<string> completion) {
    map<string, int> participantMap; // 참가자map (이름,명수)
    string participantName;
    for(int i=0;i<participant.size();i++){
        participantName = participant[i];
        if(participantMap.find(participant[i])==participantMap.end()){
            participantMap[participantName] = 1;
        }else{
            participantMap[participantName] = 
                participantMap[participantName]+1;
        }
    }
    
    // 참가자map에서 completion한 사람 한명씩 제거
    for(int i=0;i<completion.size();i++){
        participantName = completion[i];
        int aParticipantNumber =
            participantMap.find(participantName)->second;
        if(aParticipantNumber==1){
            participantMap.erase(participantName);
        }else if(aParticipantNumber>1){
            participantMap[participantName] = 
                aParticipantNumber-1;
        }
    }
    
    string answer = participantMap.begin()->first;
    return answer;
}
