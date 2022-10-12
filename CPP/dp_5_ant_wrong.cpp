#include <iostream>
using namespace std;

int N;
int K[110][2]; // 식량 창고에 저장된 식량의 값, 약탈 여부 
int DP[110]; // 얻을 수 있는 식량의 최대값 

/* wrong case
2 6 8 7 1 2 3 => 6,7,3 약탈해서 16이어야 하는데  
8,3,2 약탈해서 13 나옴 
*/

int getMaxValueIndex ();
void visit(int index);
int main(){ // N^2
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> K[i][0];
	}
	
	int maxIndex = 0;
	for(int i=1;i<=N;i++){ // N번  
		maxIndex = getMaxValueIndex(); // N번 
		if(maxIndex<0)	break;
		
		// non-Tivial Case
		DP[i] = DP[i-1] + K[maxIndex][0];
		visit(maxIndex);
	}
	
	for(int i=0;i<=N;i++){
		cout << DP[i] << " ";
	}
	cout << endl;
	
	cout << DP[N];
	
	return 0;
}

int getMaxValueIndex (){
	int maxValue = -1;
	int maxIndex = 0;
	for(int i=1;i<=N;i++){
		if(K[i][1]==1)	continue;
		if(K[i][0]>maxValue){
			maxValue = K[i][0];
			maxIndex = i;
		}
	}
	return maxIndex;
}

void visit(int index){
	// 방문 체크 
	K[index][1] = 1; 
	// 인접한 곳 방문 체크 
	if(index>1) K[index-1][1] = 1;
	if(index<N) K[index+1][1] = 1;
}
