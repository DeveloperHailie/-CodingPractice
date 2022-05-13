#include <set>
#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// set
	set<int> s;
	
	s.insert(1);
	s.insert(2);
	s.insert(4);
	s.insert(3);
	s.erase(2);
	
	for(auto iter=s.begin(); iter!=s.end();iter++){
		cout << *iter << " ";
	}
	cout <<endl;
	
	auto findIter = s.find(1);
	if(findIter != s.end()){
		cout << "s는 1을 가지고 있음";
	}
	
	
	return 0;
	
}
