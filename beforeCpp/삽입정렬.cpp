#include <iostream>
using namespace std;

int main(){
  
  // ���� ����
  
  int list[10] = {9,4,3,7,10,34,1,2,22,8};
  
  // i : bar
  for(int i=1;i<10;i++){
    // j : bar ������ ���� bar ���� �迭�� ��� �� ���ΰ�
    for(int j=i;j>0;j--){
      // ���� �迭�� �����ִ� ���� [i]���� ũ�� swap
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
