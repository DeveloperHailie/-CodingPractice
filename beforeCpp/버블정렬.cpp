#include <iostream>
using namespace std;

int main(){
  
  // ���� ����
  
  int list[10] = {9,4,3,7,10,34,1,2,22,8};
  
  int n = 10;
  // n�� �Ȱڴ�. (n : �迭 size)
  for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
      if(list[j]>list[j+1]){
        int temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
  
  for(int i=0;i<10;i++){
    cout << list[i] << " ";
  }
  
  cout << "\n";
  
  // i : bar
  for(int i=n-1;i>=0;i--){
    // j : bar�� ���� �迭, swap ���� �ִ��� ���� ������
    for(int j=0;j<i;j++){
      if(list[j]>list[j+1]){
        int temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
  
  for(int i=0;i<10;i++){
    cout << list[i] << " ";
  }
  
  return 0;
}
