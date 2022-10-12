#include <iostream>
#include <queue>
using namespace std;

int N,M;
int grid[1010][1010];
struct xy {
	int x,y;
};
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
queue<struct xy> q;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> M >> N;
	for(int i=1 ; i<=N ; i++){
		for(int j=1 ; j<=M ; j++){
			cin >> grid[i][j];
			if(grid[i][j] == 1){ // start : 상한 귤 
				q.push({i,j});
			}
		}
	}
	
	int day = 0;
	while(!q.empty()){
		struct xy c = q.front();
		q.pop();
		
		for(int i=0 ; i<4 ; i++){
			int nx = c.x+dx[i];
			int ny = c.y+dy[i];
			
			if(!(0<nx && nx<=N && 0<ny && ny<=M)){ // out of bound
				continue;
			}
			if(grid[nx][ny]!=0){ // 상하지 않은 귤이 아니면
				continue; 
			}
			
			q.push({nx, ny});
			grid[nx][ny] = grid[c.x][c.y] + 1;
			day = grid[nx][ny];
		}
	}
	
	// 모두 상한 경우 인지 아닌지 
	for(int i=1 ; i<=N ; i++){
		for(int j=1 ; j<=M ; j++){
			if(grid[i][j] == 0){ // 상하지 않은 귤 
				cout << -1;
				return 0; 
			}
		}
	}
	day = day==0 ? day : day-1;
	cout <<  day ;
	
	return 0;
}

/*
https://www.acmicpc.net/problem/7576
10284kb, 84ms
*/
