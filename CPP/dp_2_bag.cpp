#include <iostream>
//#include <algorithm>
using namespace std;

int N, K;
int W[1010];
int P[1010];
int DP[1010][10010];

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		cin >> W[i] >> P[i];
	}
	
	int w;
	int p;
	for(int i=1;i<=N;i++){ // i는 보석 
		for(int j=1;j<=K;j++){ // j는 무게 
			w = W[i];
			p = P[i];
			// DP[i][j] 관련 점화식 
			if(j < W[i]){
				DP[i][j] = DP[i-1][j];
			}else{
				DP[i][j] = max(DP[i-1][j], DP[i-1][j-w]+p);
			}
		}
		cout << endl;
	}
	
	cout << DP[N][K];	
	
	return 0;
}

/*
4 14
2 40
5 110
10 200
3 50

=> 250
*/
