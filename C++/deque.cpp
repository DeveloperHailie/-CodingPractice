#include <deque>
#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//deque
	deque<int> dq1;
	deque<int> dq2(3); //0,0,0
	deque<int> dq3(3,2); //2,2,2
	
	dq1.push_front(1);
	dq1.push_back(3);
	dq1.push_back(2); //1,3,2
	
	cout << "dq1 front,back,[1]: ";
	cout << dq1.front() << " "; //1
	cout << dq1.back() << " "; //2
	cout << dq1[1] << endl; //3
	
	dq1.pop_back(); //1,2
	dq1.erase(dq1.begin()+1); //1
	dq1.push_front(100); //100,1
	
    deque<int>::iterator iter;
    cout << "dq1: " ;
    for(iter = dq1.begin(); iter != dq1.end() ; iter++){
        cout << *iter << " ";
    }
    cout << endl << endl;

	
	return 0;
	
}
