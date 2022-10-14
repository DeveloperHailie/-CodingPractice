#include <string>
#include <vector>
#include <queue>
using namespace std;

int network[60][60];
int visited[60];
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    words.push_back(begin); // begin도 push하기
    
    int nodeCnt = words.size();
    int targetIndex = -1;
    for(int i=0;i<nodeCnt;i++){
        if(words[i]==target)
            targetIndex = i;
        bool linked;
        for (int j=(nodeCnt-1);i<j;j--){
            linked = false;
            // word[i]와 word[j] 연결 관계 확인
            for(int k=0;k<words[0].size();k++){ // 글자 수 모두 같음
                if(words[i][k] != words[j][k]){
                    if(linked){ //이전에 != 경우 있었음
                        linked = false;
                        break;
                    }else{ // 이전에 같은 경우 없었음
                        linked = true;
                    }
                }
            }
            if(linked){ // 양방향
                network[i][j] = 1;
                network[j][i] = 1;
            }
        }
    }
    
    if(targetIndex==-1) return 0;
    
    queue<int> q;
    q.push(nodeCnt-1); //마지막에 집어넣은 begin
    visited[nodeCnt-1] = 1;
    while(!q.empty()){
        int currentIndex = q.front();
        q.pop();
        
        if(currentIndex == targetIndex) break;
        
        for(int i=0;i<nodeCnt;i++){
            if(visited[i]!=0) continue; // 방문했음
            if(network[currentIndex][i]==0) continue; // 미연결
            q.push(i);
            visited[i] = visited[currentIndex]+1;
        }
    }
    
    answer = visited[targetIndex] - 1;
    return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/43163
