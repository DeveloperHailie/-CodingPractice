#include <iostream>
using namespace std;

int main(){
	
	cin.tie(NULL); //cin, cout 관계 없도록 만듦, cout 버퍼 플러쉬 해주지만 속도는 향상 
	ios::sync_with_stdio(false); //cin, stdibn 동기화 false, 호출 순서는 보장할 수없지만 속도 향상 
	
	int n;
	cin >> n;
	
	int arr[n];
	
	int *arrP;
	arrP = new int[n];
	delete[] arrP;
	 
	
	return 0;
}
