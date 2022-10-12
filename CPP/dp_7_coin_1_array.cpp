#include <iostream>
using namespace std;
#define X 10010

int N,M;
int COIN[110];
int DP[10010];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M ; // N ȭ�� ���� ����, M ������ �ϴ� ��ġ 
	for(int i=1;i<=N;i++){
		cin >> COIN[i];
	}
	
	/* ������ �迭���� �� �࿡ �����ߴ� ����
	������ �迭���� ������ �����ϴ� ��� 
	i : 1..N, j : 1..M
	DP[i][j] = min(DP[i-1][j], DP[i][j-COIN[i]]+1)
	=>
	DP[i] = min(DP[i], DP[i-COIN[j]]+1)
	*/
	for(int i=0;i<=M;i++){
		DP[i] = X; 
	}
	
	// Trivial Case
	DP[0] = 0;
	
	// Non-Trivial Case1
	for(int i=1;i<=M;i++){
		// coin[1..j]�� �̿��Ͽ� i���� ���� ���� �ּҰ��� 
		for(int j=1;j<=N;j++){
				DP[i] = min(DP[i], DP[i-COIN[j]]+1);
			}
		}
	}
	
	// Non-Trivial Case2 
	/*
	for(int i=1;i<=N;i++){ 
		// coin[i]�� �̿��Ͽ� j(=COIN[i]..M)���� ���� ���� �ּҰ��� 
		for(int j=COIN[i];j<=M;j++){
			if(j-COIN[i]>=0 && DP[j-COIN[i]]!=X){
				DP[j] = min(DP[j], DP[j-COIN[i]]+1);
			}
		}
	}
	*/
	
	if(DP[M]>=X)
		cout << -1;
	else
		cout << DP[M];
		
	return 0;
}

/*
https://www.acmicpc.net/problem/2294
3 15
1
5
12

3

NTC1: 2060KB, 0ms 
NTC2: 2060KB, 4ms 
*/
