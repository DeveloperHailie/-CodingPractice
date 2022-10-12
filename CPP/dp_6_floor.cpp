#include <iostream>
using namespace std;

int N;
int DP[1010];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	
	// Tirival Case
	DP[1] = 1; DP[2]=3; 
	for(int i=3;i<=N;i++){ // Non-Trivial Case 
		DP[i] = (DP[i-1] + DP[i-2]*2) % 796796;
	}
	
	cout << DP[N];
	
	return 0;
} 
