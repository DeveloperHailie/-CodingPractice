#include <iostream>
using namespace std;

int N;
int L;
int grid[110][110];
int visited[110];
int virusComputer = 0;
 
void dfs(int computer){
	for(int i=1;i<=N;i++){
		if(i==computer)	continue; // �ڱ��ڽ� 
		if(grid[computer][i] != 1)	continue; // �̿��� �� 
		if(visited[i]==1)	continue; // ��湮 �� 
		
		// �湮(����) ó��
		visited[i] = 1; 
		// ���̷��� ī��Ʈ
		virusComputer++;
	
		dfs(i); 
	} 
}


int main(){
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> L;
	int tempX, tempY;
	for(int i=0;i<L;i++){
		cin >> tempX >> tempY;
		grid[tempX][tempY] = 1;
		grid[tempY][tempX] = 1;
	}
	
	dfs(1);	
	
	cout << virusComputer-1; // 1�� ���� 
	 
	return 0;
}

/*
https://www.acmicpc.net/problem/2606
2068KB, 0ms
6
5
1 2
1 3
1 4
1 5
1 6
=> 5
7
6
1 2
2 3
1 5
5 2
5 6
4 7
=> 4
*/
