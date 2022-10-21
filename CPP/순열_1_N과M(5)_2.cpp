#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int list[10];
int mask[10];
int main(){
	
	//cin.tie(0);
	//ios::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> list[i];
	}
	
	sort(list, list+N); 
	
	// nPr
	
	set<vector<int>> result;
	do{
		vector<int> temp;
		for(int i=0;i<M;i++){
			temp.push_back(list[i]); //순열에서 0~(r-1)까지만  
		}
		result.insert(temp); // 자동으로 오름차순이나 내림차순으로 정렬
	}while(next_permutation(list,list+N)); 
	
	for(set<vector<int>>::iterator iter=result.begin(); iter!=result.end() ; iter++){
		for(int i=0;i<M;i++){
			cout << (*iter)[i] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
// https://www.acmicpc.net/problem/15654
// 6384KB	64ms
/*
	// 조합 nCr (1)
	 
	for(int i=M;i<N;i++){
		mask[i]=1; //N-M개 1로 채우기, 0이 선택 
	}
	
	do{
		for(int i=0;i<N;i++){
			if(mask[i]==0){
				cout << list[i]	<< " ";		
			}
		}
		cout << endl;
	}while(next_permutation(mask,mask+N));
	
	----
	
	// 조합 nCr (2)
	
	for(int i=0;i<M;i++){
		mask[i]=1; //M개 1로 채우기, 1이 선택 
	}
	
	do{
		for(int i=0;i<N;i++){
			if(mask[i]==1){
				cout << list[i]	<< " ";		
			}
		}
		cout << endl;
	}while(prev_permutation(mask,mask+N));
	
	---
	
	// 순열 nPn
	do{
		for(int i=0;i<N;i++){
			cout << list[i]	<< " ";	
		}
		cout << endl;
	}while(next_permutation(list,list+N)); 
	

*/
