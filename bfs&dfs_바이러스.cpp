#include <iostream>
#include <queue>
using namespace std;

// 컴퓨터수<=100 
int computer[101][101];
int visited[101];
// 결과 값
int result = 0;

void dfs(int ver, int size){
	result++;
	visited[ver] = true;
	for(int j=1;j<=size;j++){
		if(computer[ver][j]==1&&visited[j]==false){
			dfs(j,size);
		}
	}
}
void bfs(int start, int size){
	queue<int> q;
	visited[start]=true;
	q.push(start);
	while(!q.empty()){
		int ver = q.front();
		result++;
		q.pop();
		for(int j=1;j<=size;j++){
			if(computer[ver][j]==1&&visited[j]==false){
				visited[j]=true;
				q.push(j);
			}
		}
	}
}
int main(){
	int count;int network;
	cin >> count;
	// 배열 초기화 
	// 배열은 0부터 시작, 컴퓨터 번호는 1부터 시작 
	for(int i=1;i<=count;i++){
		for(int j=1;j<=count;j++){
			computer[i][j] = 0;
		}
	}
	cin >> network;
	// 컴퓨터간 연결 관계 
	int t1,t2;
	for(int n=0;n<network;n++){
		cin >> t1 >> t2;
		computer[t1][t2] = 1;
		computer[t2][t1] = 1;
	}
	// 방문 여부 판단 배열 초기화 
	for(int i=1;i<=count;i++){
		visited[i] = false;
	} 
	
	// 1번 컴퓨터가 바이러스에 걸림 
	dfs(1,count);
	//bfs(1,count); 
	
	// 결과 출력 
	//1번 컴퓨터를 통해 이므로 1번 컴퓨터는 제외해야한다. 
	cout << result-1;	
	return 0;
} 
