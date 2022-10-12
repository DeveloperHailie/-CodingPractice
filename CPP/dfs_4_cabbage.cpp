#include <iostream>
using namespace std;

int T, M, N, K;
int grid[60][60]; // 0:배추X, 1:배추O, -1:방문 
int cnt = 0;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
void dfs(int x, int y){
	grid[x][y] = -1; // 마킹, 방문처리
	
	// 이동, 재귀호출 
	for(int i=0 ; i<4 ; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(!(0<=nx && nx<M && 0<=ny && ny<N)){ // out of bound
			continue;
		}
		if(grid[nx][ny] != 1){ // 배추 안심은 곳 or 재방문 
			continue;
		}
		
		dfs(nx,ny);				
	} 
}


int main(){
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> T ;

	for(int t=0 ; t<T ; t++){
		cnt = 0;
		
		cin >> M >> N >> K;
		
		int tempX, tempY; 
		for(int i=0;i<K;i++){
			cin >> tempX >> tempY;
			grid[tempX][tempY] = 1;
		}

		// 순회하면서 시작점 찾기 
		for(int i=0 ; i<M ; i++){ // x
			for(int j=0 ; j<N ; j++){ // y
				if(grid[i][j]==1){
					cnt++;
					dfs(i,j);
				}
			}
		}
		
		cout << cnt << "\n";
	}
	
	return 0;
}

// https://www.acmicpc.net/problem/1012
// 2036KB, 0ms
