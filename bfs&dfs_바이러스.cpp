#include <iostream>
#include <queue>
using namespace std;

// ��ǻ�ͼ�<=100 
int computer[101][101];
int visited[101];
// ��� ��
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
	// �迭 �ʱ�ȭ 
	// �迭�� 0���� ����, ��ǻ�� ��ȣ�� 1���� ���� 
	for(int i=1;i<=count;i++){
		for(int j=1;j<=count;j++){
			computer[i][j] = 0;
		}
	}
	cin >> network;
	// ��ǻ�Ͱ� ���� ���� 
	int t1,t2;
	for(int n=0;n<network;n++){
		cin >> t1 >> t2;
		computer[t1][t2] = 1;
		computer[t2][t1] = 1;
	}
	// �湮 ���� �Ǵ� �迭 �ʱ�ȭ 
	for(int i=1;i<=count;i++){
		visited[i] = false;
	} 
	
	// 1�� ��ǻ�Ͱ� ���̷����� �ɸ� 
	dfs(1,count);
	//bfs(1,count); 
	
	// ��� ��� 
	//1�� ��ǻ�͸� ���� �̹Ƿ� 1�� ��ǻ�ʹ� �����ؾ��Ѵ�. 
	cout << result-1;	
	return 0;
} 
