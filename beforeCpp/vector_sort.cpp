#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// sort(v.begin(),v.end(),compare);
// stable_sort(v.begin(),v.end(),compare); 비교대상같으면 먼저 온거 먼저 처리 
bool compareString(string a, string b){
	if(a.length()==b.length())
		return a < b;
	else
		return a.length() < b.length();
}
bool compareInt(int a, int b){
	return a<b;
}
bool compareString2(string a, string b){
	return a[0]<b[0]; //문자열.length() 
}

int main(){
	// 생성 및 초기화 
	vector<int> v1;
	vector<int> v2(5); // {0,0,0,0,0}
	vector<int> v3 = {1,2,3,2}; // 1,2,3,2로 값 초기화
	vector<int> v4[] = {{1,2,3},{4}}; // 열은 고정, 행은 가변인, 백터 배열 
	vector<vector<int>> v5; // 열,행 둘다 가변인 2차원 백터 생성 
	vector<int> v6;
	v6.assign(5,10); // {10,10,10,10,10}
	vector< pair<int,int> > v7;
	vector<string> v8 = {"hi", "hello", "abc", "zzz"};
	vector<string> v9 = {"hi", "hello", "abc", "zzz"};
		
	// 삽입 및 제거
	v1.push_back(1);  
	v1.push_back(2);
	v1.push_back(3); // {1,2,3}
	v1.pop_back();  // {1,2}
	v1.emplace(v1.begin()+1, 100); // {1,100,2}, v1.begin()은 주소값
	v1.emplace(v1.begin()+1, 200); // {1,200,100,2}
	v1.erase(v1.begin()+1); // {1,100,2}
	
	v5.resize(4, vector<int>(3,0)); //{ {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} }
	
	v7.push_back(pair<int,int>(1,2));
	v7.push_back(pair<int,int>(3,4));
	v7.push_back(pair<int,int>(5,6)); // { (1,2), (3,4), (5,6)}
	
	// 정렬
	sort(v3.begin(), v3.end(), compareInt); // {1,2,2,3}
	sort(v8.begin(), v8.end(), compareString2); // {abc, hi, hello, zzz}
	stable_sort(v9.begin(), v9.end(), compareString2);
	 
	// 출력 
	cout << "v1: " ;
	for(int i=0;i<v1.size();i++){
		cout << v1[i] << " ";
	}
	cout << endl;
	
	cout << "v2: " ;
	for(int i=0;i<v2.size();i++){
		cout << v2[i] << " ";
	}
	cout << endl;
	
	cout << "v3: " ;
	for(int i=0;i<v3.size();i++){
		cout << v3[i] << " ";
	}
	cout << endl;
	
	cout << "v4: " ;
	for(int i=0;i<2;i++){
		for(int j=0;j<v4[i].size();j++){
			cout << v4[i][j] << ",";
		}
		cout << " / ";
	}
	cout << endl;
	
	cout << "v5: " ;
	for(int i=0;i<v5.size();i++){
		for(int j=0;j<v5[i].size();j++){
			cout << v5[i][j] << ",";
		}
		cout << " / ";
	}
	cout << endl;
	
	cout << "v6: " ;
	for(int i=0;i<v6.size();i++){
		cout << v6[i] << " ";
	}
	cout << endl;
	
	cout << "v7: " ;
	for(int i=0;i<v7.size();i++){
		cout << v7[i].first << "," << v7[i].second << " / ";
	}
	cout << endl;
	
	cout << "v8: " ;
	for(int i=0;i<v8.size();i++){
		cout << v8[i] << " ";
	}
	cout << endl;
	
	cout << "v9: " ;
	for(int i=0;i<v9.size();i++){
		cout << v9[i] << " ";
	}
	cout << endl;
	
	return 0; 
}
