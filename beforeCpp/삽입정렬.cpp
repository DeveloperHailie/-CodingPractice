#include <iostream>
using namespace std;

int main(){
  
  // 삽입 정렬
  
  int list[10] = {9,4,3,7,10,34,1,2,22,8};
  
  // i : bar
  for(int i=1;i<10;i++){
    // j : bar 오른쪽 값이 bar 왼쪽 배열의 어디에 들어갈 것인가
    for(int j=i;j>0;j--){
      // 왼쪽 배열에 속해있는 값이 [i]보다 크면 swap
      if(list[j-1]>list[j]){
        int temp = list[j-1];
        list[j-1] = list[j];
        list[j] = temp;
      }else break;
    }
  }
  
  for(int i=0;i<10;i++){
    cout << list[i] << " ";
  }
  
  return 0;
}
