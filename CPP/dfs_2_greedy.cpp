#include <iostream>
#include <algorithm>
using namespace std;

// 딸기 양(자연수) <= 1,000,000 이므로 
// grid 배열 int 타입으로도 충분하다  

int N;
int grid[550][550];
int dp[550][550];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dfs(int x, int y){
	// memoization
	if(dp[x][y] != 0){
		return dp[x][y];
	}
	
	for(int i=0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if (!( 0<nx&&nx<=N && 0<ny&&ny<=N)){
			continue;
		}
		if(grid[nx][ny] <= grid[x][y]){
			continue;
		}
		dp[x][y] = max(dp[x][y], dfs(nx,ny)+1);
	}
	
	return dp[x][y];
	
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> grid[i][j];
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			// memoization
			if(dp[i][j] == 0)
				dp[i][j] = dfs(i,j);
			
		}
	}
	
	int max = 0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(dp[i][j]>max)
				max = dp[i][j];
		}
	}
	cout << max+1 ;
	
	return 0;
}

// https://www.acmicpc.net/problem/1937
