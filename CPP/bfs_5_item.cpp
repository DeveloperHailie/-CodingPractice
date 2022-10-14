#include <string>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int cnt[110][110];
int map[110][110];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
struct xy {
    int x,y;
};
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    // setting mapping (*2)
    int x1, y1, x2, y2;
    for(int i=0;i<rectangle.size();i++){
        x1 = rectangle[i][0]*2 - 1;
        y1 = rectangle[i][1]*2 - 1;
        x2 = rectangle[i][2]*2 - 1;
        y2 = rectangle[i][3]*2 - 1;
        for(int x=x1;x<=x2;x++){
            for(int y=y1;y<=y2;y++){
                if(map[x][y]==-1){
                    continue; //can not go
                }
                if(x==x1 || y==y1 || x==x2 || y==y2){
                    map[x][y] = 1; //can go
                }else{
                    map[x][y] = -1; //can not go
                }
            }
        }
    }
    
    // setting start, end (*2)
    int startX = characterX*2 - 1;
    int startY = characterY*2 - 1;
    int endX = itemX*2 - 1;
    int endY = itemY*2 - 1;
    
    queue<struct xy> q;
    q.push({startX, startY});
    cnt[startX][startY] = 1;
    
    while(!q.empty()){
        struct xy current = q.front();
        q.pop();
        
        // finish
        if(current.x==endX && current.y==endY){
            break;
        }
        
        // move
        for(int i=0;i<4;i++){
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            
            // out of bound
            if(!(1<=nx&&nx<=110&&1<=ny&&ny<=110))  continue;
            // can not go
            if(map[nx][ny]!=1)  continue;
            // visited
            if(cnt[nx][ny]!=0)  continue;
            
            //marking
            cnt[nx][ny] = cnt[current.x][current.y] + 1;
            q.push({nx,ny});
        }
    }
    
    answer = cnt[endX][endY]/2; 
    
    return answer;
}

/* https://school.programmers.co.kr/learn/courses/30/lessons/87694
채점 결과
정확성: 100.0
합계: 100.0 / 100.0
*/
