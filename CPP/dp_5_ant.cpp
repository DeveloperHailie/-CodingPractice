#include <iostream>
using namespace std;

int N; // 식량 창고 개수 
int K[1010]; // 식량 창고에 저장된 식량의 값
int DP[110]; // 얻을 수 있는 식량의 최대값 

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> K[i];
	}
	
	// Trivial Case
	DP[1] = K[1];
	DP[2] = max(K[1],K[2]);
	for(int i=1;i<=N;i++){ // N번 
		// non-Tivial Case 
		DP[i] = max(DP[i-1],DP[i-2]+K[i]);
	}

	cout << DP[N];
	
	return 0;
}

/*
4
1 3 1 5
=> 8

7
2 6 8 7 1 2 3 
=> 16
*/
