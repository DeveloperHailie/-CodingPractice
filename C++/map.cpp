#include <map>
#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// map
	// (key, value)
	map<int,int> m1; // 자동 key값 기준 오름차순 정렬 

	// insert
	m1.insert({100,-109});
	m1.insert({101,-701});
	m1.insert({90,-887});
	m1.insert({81,91}); // (81,91)(90,887)(100,-109)(101,-701) 

	
	// search
	if(m1.find(100)!=m1.end()){
		cout << "m1[100] " << m1[100] << endl;
	}
	
	// remove
	m1.erase(100); // (81,91)(90,887)(101,-701) 
	
	cout << "m1: ";
	for(auto iter=m1.begin(); iter!=m1.end(); iter++){
		cout << iter->first << "," << iter->second << " / ";
	}
	
	//m1.erase(m1.begin()+1); // 
	m1.erase(100);
	
	return 0;
	
}
