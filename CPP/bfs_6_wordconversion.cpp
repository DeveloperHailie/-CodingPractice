#include <string>
#include <vector>
#include <queue>
using namespace std;

int network[60][60];
int visited[60];
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    words.push_back(begin); // begin�� push�ϱ�
    
    int nodeCnt = words.size();
    int targetIndex = -1;
    for(int i=0;i<nodeCnt;i++){
        if(words[i]==target)
            targetIndex = i;
        bool linked;
        for (int j=(nodeCnt-1);i<j;j--){
            linked = false;
            // word[i]�� word[j] ���� ���� Ȯ��
            for(int k=0;k<words[0].size();k++){ // ���� �� ��� ����
                if(words[i][k] != words[j][k]){
                    if(linked){ //������ != ��� �־���
                        linked = false;
                        break;
                    }else{ // ������ ���� ��� ������
                        linked = true;
                    }
                }
            }
            if(linked){ // �����
                network[i][j] = 1;
                network[j][i] = 1;
            }
        }
    }
    
    if(targetIndex==-1) return 0;
    
    queue<int> q;
    q.push(nodeCnt-1); //�������� ������� begin
    visited[nodeCnt-1] = 1;
    while(!q.empty()){
        int currentIndex = q.front();
        q.pop();
        
        if(currentIndex == targetIndex) break;
        
        for(int i=0;i<nodeCnt;i++){
            if(visited[i]!=0) continue; // �湮����
            if(network[currentIndex][i]==0) continue; // �̿���
            q.push(i);
            visited[i] = visited[currentIndex]+1;
        }
    }
    
    answer = visited[targetIndex] - 1;
    return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/43163
