#include<vector>
#include<queue>
using namespace std;

int n,m;
struct xy{
  int x,y;  
};
int grid[110][110];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    maps[0][0] = 2;
    queue<struct xy> q;
    q.push({0,0});
    while(!q.empty()){
        struct xy current = q.front();
        q.pop();
        if(current.x==(n-1) && current.y==(m-1))    break;
        
        for(int i=0;i<4;i++){
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            
            if(!(0<=nx && nx<n && 0<=ny && ny<m))  continue;
            if(maps[nx][ny] != 1)    continue;
            
            maps[nx][ny] = maps[current.x][current.y] + 1;
            q.push({nx,ny});
        }
    }
    
    if(maps[n-1][m-1]<=1) answer = -1;
    else answer = maps[n-1][m-1] - 1;
    
    return answer;
}

// https://school.programmers.co.kr/learn/courses/30/lessons/1844
/* 게임 맵 최단거리
정확성: 69.9
효율성: 30.1
합계: 100.0 / 100.0
*/ 
