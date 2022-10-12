#include <iostream>
using namespace std;

int N; // �ķ� â�� ���� 
int K[1010]; // �ķ� â�� ����� �ķ��� ��
int DP[110]; // ���� �� �ִ� �ķ��� �ִ밪 

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
	for(int i=1;i<=N;i++){ // N�� 
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
