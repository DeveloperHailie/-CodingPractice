#include <iostream>
#include <algorithm>
using namespace std;

string S1, S2;
int DP[1010][1010];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> S1 >> S2;
	
	for(int i=1;i<=S1.length();i++){
		for(int j=1;j<=S2.length();j++){
			if(S1[i-1]==S2[j-1]){
				DP[i][j] = DP[i-1][j-1] + 1;
			}else{
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
			}
		}
	}
	
	cout << DP[S1.length()][S2.length()];
	return 0;
}

/* https://www.acmicpc.net/problem/9251
ACAYKP
CAPCAK

4
-
CAPCAK
ACACKP

4
*/
