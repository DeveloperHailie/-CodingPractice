#include <iostream>
using namespace std;

int main(){
	
	cin.tie(NULL); //cin, cout ���� ������ ����, cout ���� �÷��� �������� �ӵ��� ��� 
	ios::sync_with_stdio(false); //cin, stdibn ����ȭ false, ȣ�� ������ ������ �������� �ӵ� ��� 
	
	int n;
	cin >> n;
	
	int arr[n];
	
	int *arrP;
	arrP = new int[n];
	delete[] arrP;
	 
	
	return 0;
}
