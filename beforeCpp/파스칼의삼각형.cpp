#include <iostream>
using namespace std;

int list[100][100];

int main(){
  
  // nCr�� n�� r �Է¹ޱ�  
  int n, r;
  cin >> n >> r;;
  
  // �迭 �ʱ�ȭ 
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      list[i][j] = 0;
    }
  }
  
  // �˰��� 
  for(int i=0;i<=n;i++){
  	for(int j=0;j<=i;j++){
  		if(j==0 || j==i){
  			list[i][j] = 1;
		}
		else
			list[i][j] = list[i-1][j-1] + list[i-1][j];
	  }
  }
  
  
  // �迭 ���  
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      if(list[i][j]!=0)
        cout << list[i][j] << " ";
    }
    cout << '\n';
  }
  
  // nCr ���ϱ� 
  cout << list[n][r]; 
  
  return 0;
}
