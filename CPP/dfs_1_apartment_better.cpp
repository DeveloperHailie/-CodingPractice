#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int grid[30][30];
int cnt = 1; // 아파트 단지 (label), 단지 총 개수 저장 
int ap[900]; // 30x30, 단지 당 아파트 개수 저장 

// 변이 
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void dfs(int x, int y);

int main(){

	cin.tie(NULL);
	//ios::sync_with_stdio(false);
	
	cin >> N; // -> scanf("%d", &N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%1d",&grid[i][j]);		
		}
	}

	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(grid[i][j] == 1){
				cnt++; // 첫 라벨은 2
				dfs(i,j);
			}
		}
	}
	

	// 단지개수 기준 오름차순 정렬해서 출력 , ap+2, ap+cnt+1
	sort(ap, ap+cnt+1); // 정렬하고자 하는 것의 주소, 마지막 저장된 위치+1 
	cout << cnt-1 << "\n"; 
	for(int i=2;i<=cnt;i++){
		cout << ap[i] << "\n";
	} 

	return 0;
}

void dfs(int x, int y){
	// 마킹 
	grid[x][y] = cnt;
	ap[cnt]++;
	
	// 재귀함수 호출 
	for(int i=0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		// 종료 조건 
		if(!(0<=nx&&nx<N&&0<=ny&&ny<N)) //out of bound
			continue;
		if(grid[nx][ny]!=1) //visited or cannot go 
			continue;
		dfs(nx, ny);
	}
}

// https://www.acmicpc.net/problem/2667


