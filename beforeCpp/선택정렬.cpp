#include <iostream>
using namespace std;

int main(){
  
  // ��������
  
  int list[10] = {9,4,3,7,10,34,1,2,22,8};
  
  // i : bar
  for(int i=0;i<10;i++){
    
	int minIndex = i;
    // j : bar ������ �迭���� �ּڰ� ã�� 
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
