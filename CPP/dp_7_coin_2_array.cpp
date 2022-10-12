#include <iostream>
using namespace std;
#define X 10010

int N,M;
int COIN[110];
int DP[110][10010];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M ;
	for(int i=1;i<=N;i++){
		cin >> COIN[i];
	}
	
	// Trivial Case
	for(int i=0;i<=N;i++){
		DP[i][0] = X;
	}
	for(int j=1;j<=M;j++){
		DP[0][j] = X;
		if(j%COIN[1]==0)
			DP[1][j] = j/COIN[1];
		else
			DP[1][j] = X;
	}
	
	// Non-Trivial Case
	for(int i=2;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(j-COIN[i]>0){
				DP[i][j] = min(DP[i-1][j], DP[i][j-COIN[i]]+1);
			}else{
				if(j%COIN[i]==0)
					DP[i][j] = j/COIN[i];
				else
					DP[i][j] = DP[i-1][j];
			}
			
		}
	}

	if(DP[N][M]>=X)
		cout << -1;
	else
		cout << DP[N][M];
	
	return 0;
}

/*
https://www.acmicpc.net/problem/2294
3 15
1
5
12

3

6324KB, 4ms 
*/
