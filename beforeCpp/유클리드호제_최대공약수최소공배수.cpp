#include <iostream>
using namespace std;

int main(){
	
	int t;
	cin >> t;
	
	int realA, realB, a, b;
	for(int i=0;i<t;i++){
		
		cin >> realA >> realB;
		a = realA;
		b = realB;
		if(a<b){
			int temp = a;
			a = b;
			b = temp;
			
		}
		// 최대 공약수
		while(b!=0){
			int temp = a;
			a = b;
			b = temp%b; 
		} 
		
		// 최소공배수 최대공약수 
		cout << a*(realA/a)*(realB/a) << " " << a << '\n';
	}
	
	
	return 0;
}
