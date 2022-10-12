#include <iostream>
#include <algorithm>
using namespace std;

int N;
int DP[30010]; 
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	
	for(int i=2;i<=N;i++){
		if(i==2 || i==3 || i==5){ // Trivial Case
			DP[i] = 1;
			continue;
		}
		// Non-Tivial Case
		DP[i] = DP[i-1]+1;
		if(i%2==0) 
			DP[i] = min(DP[i], DP[i/2]+1);
		if(i%3==0) 
			DP[i] = min(DP[i], DP[i/3]+1);
		if(i%5==0) 
			DP[i] = min(DP[i], DP[i/5]+1);
	}
	
	cout << DP[N];
	
	return 0;
}
