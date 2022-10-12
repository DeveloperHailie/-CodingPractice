#include <iostream>
using namespace std;
#define X 5001

int main(){
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	int dp[5000]={0,X,X,1,X,1};
	
	for(int i=6;i<=n;i++){ 
		// dp[i] 관련 점화식 
		dp[i] = min(dp[i-5]+1, dp[i-3]+1) ; 
	}
	
	if(dp[n]>=X){
		cout << -1;
	}else{
		cout << dp[n];
	}
	
	return 0;
}

// https://www.acmicpc.net/problem/2839
