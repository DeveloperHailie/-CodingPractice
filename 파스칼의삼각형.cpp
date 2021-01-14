#include <iostream>
using namespace std;

int list[100][100];

int main(){
  
  // nCr의 n과 r 입력받기  
  int n, r;
  cin >> n >> r;;
  
  // 배열 초기화 
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      list[i][j] = 0;
    }
  }
  
  // 알고리즘 
  for(int i=0;i<=n;i++){
  	for(int j=0;j<=i;j++){
  		if(j==0 || j==i){
  			list[i][j] = 1;
		}
		else
			list[i][j] = list[i-1][j-1] + list[i-1][j];
	  }
  }
  
  
  // 배열 출력  
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      if(list[i][j]!=0)
        cout << list[i][j] << " ";
    }
    cout << '\n';
  }
  
  // nCr 구하기 
  cout << list[n][r]; 
  
  return 0;
}
