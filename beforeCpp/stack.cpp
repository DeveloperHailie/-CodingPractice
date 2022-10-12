#include <stack>
#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// stack
	stack<int> s;
	
	s.push(1);
	s.push(2);
	s.push(3);
	
	cout << "top element: " << s.top() << endl; //3
	
	s.pop(); //3 삭제 
	
	stack<int> s2 = s;
	while(!s2.empty()){
		cout << s2.top() << ",";
		s2.pop();
	}
	cout << endl;
	
	cout << "s empty?: " << (s.empty()?true:false) << endl; //false(0)
	cout << "s2 empty?: " << (s2.empty()?true:false) << endl; //true(1)
	
	return 0;
	
}
