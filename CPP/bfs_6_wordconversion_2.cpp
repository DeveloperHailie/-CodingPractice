#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int visited[60];
bool linked(string s1, string s2){
    int notSameCnt = 0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
            notSameCnt++;
        }
    }
    
    if(notSameCnt==1)  return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    words.push_back(begin); // begin도 push하기
    int nodeCnt = words.size();
    
    queue<int> q;
    q.push(nodeCnt-1); //마지막에 집어넣은 begin
    visited[nodeCnt-1] = 1;
    
    while(!q.empty()){
        int currentIndex = q.front();
        q.pop();
        
        cout << currentIndex << " " << words[currentIndex] << endl;
        if(words[currentIndex] == target){
            answer = visited[currentIndex]-1;
        }
        
        for(int i=0;i<nodeCnt;i++){
            if(visited[i]!=0) continue; // 방문했음
            if(!linked(words[currentIndex],words[i])) continue; // 미연결
            q.push(i);
            visited[i] = visited[currentIndex]+1;
        }
    }
    
    return answer;
}
