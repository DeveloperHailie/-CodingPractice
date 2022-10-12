#include <iostream>
using namespace std;

int main(){
  
  // 선택정렬
  
  int list[10] = {9,4,3,7,10,34,1,2,22,8};
  
  // i : bar
  for(int i=0;i<10;i++){
    
	int minIndex = i;
    // j : bar 오른쪽 배열에서 최솟값 찾기 
    for(int j=i;j<10;j++){
      if(list[minIndex]>list[j]){
        minIndex = j;
      }
    }
    
    // [i] [j] swap 
    int temp = list[i];
    list[i] = list[minIndex];
    list[minIndex] = temp;
    
  }
  
  for(int i=0;i<10;i++){
    cout << list[i] << " ";
  }
  
  return 0;
}
