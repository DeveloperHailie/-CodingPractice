#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    for(int i=0;i<completion.size();i++){
        vector<string>::iterator completionPeople = 
            find(participant.begin(), participant.end(),completion[i]);
        if(completionPeople!=participant.end()){
            participant.erase(completionPeople);
        }
    }
    
    string answer = participant[0];
    return answer;
}
