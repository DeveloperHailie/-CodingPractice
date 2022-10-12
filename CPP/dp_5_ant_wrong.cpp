#include <iostream>
using namespace std;

int N;
int K[110][2]; // �ķ� â�� ����� �ķ��� ��, ��Ż ���� 
int DP[110]; // ���� �� �ִ� �ķ��� �ִ밪 

/* wrong case
2 6 8 7 1 2 3 => 6,7,3 ��Ż�ؼ� 16�̾�� �ϴµ�  
8,3,2 ��Ż�ؼ� 13 ���� 
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
	for(int i=1;i<=N;i++){ // N��  
		maxIndex = getMaxValueIndex(); // N�� 
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
	// �湮 üũ 
	K[index][1] = 1; 
	// ������ �� �湮 üũ 
	if(index>1) K[index-1][1] = 1;
	if(index<N) K[index+1][1] = 1;
}
