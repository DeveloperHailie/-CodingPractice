#include <string>
#include <vector>

using namespace std;

int visited[210];

void dfs(int node, int n, vector<vector<int>> grid){
    //node 방문 처리
    visited[node] = 1;
    
    for(int k=0;k<n;k++){
        if(visited[k]) //이미 방문
            continue;
        if(grid[node][k]!=1) //미연결시 못감
            continue;
        if(node==k) //자기 자신은 방문 못함
            continue;
        dfs(k, n, grid);
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int networkCnt = 0;
    
    for(int i=0;i<n;i++){
        if(visited[i]==0){ // 미방문 시 시작
            networkCnt++;
            dfs(i, n, computers);
        }
    }
    
    return networkCnt;
}

// https://school.programmers.co.kr/learn/courses/30/lessons/43162#
