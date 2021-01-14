#include <iostream>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  for(int i=2;1<n;){
    if(n%i==0){
      cout << i << " ";
      n = n/i;
    }
    else  i++;
  }
  
  return 0;
}
