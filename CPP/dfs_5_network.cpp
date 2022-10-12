#include <string>
#include <vector>

using namespace std;

int visited[210];

void dfs(int node, int n, vector<vector<int>> grid){
    //node �湮 ó��
    visited[node] = 1;
    
    for(int k=0;k<n;k++){
        if(visited[k]) //�̹� �湮
            continue;
        if(grid[node][k]!=1) //�̿���� ����
            continue;
        if(node==k) //�ڱ� �ڽ��� �湮 ����
            continue;
        dfs(k, n, grid);
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int networkCnt = 0;
    
    for(int i=0;i<n;i++){
        if(visited[i]==0){ // �̹湮 �� ����
            networkCnt++;
            dfs(i, n, computers);
        }
    }
    
    return networkCnt;
}

// https://school.programmers.co.kr/learn/courses/30/lessons/43162#
