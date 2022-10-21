#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int list[10];
int mask[10];
int main(){
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> list[i];
	}
	
	sort(list, list+N); 
	
	// nPr
	
	for(int i=0;i<M;i++){
		mask[i]=1; //M개 1로 채우기, 1이 선택 
	}
	
	vector<vector<int> > result; 
	do{
		vector<int> choice;
		for(int i=0;i<N;i++){
			if(mask[i]==1){
				choice.push_back(list[i]);	
			}
		}
		sort(choice.begin(),choice.end()); // n 개 중 r개 뽑기 (조합) 
		do{ // r개 순열 
			result.push_back(choice);
		}while(next_permutation(choice.begin(),choice.end()));
	}while(prev_permutation(mask,mask+N));
	
	sort(result.begin(),result.end()); // 순서대로 출력해야 하므로 
	for(int i=0;i<result.size();i++){
		for(int j=0;j<M;j++){
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
// https://www.acmicpc.net/problem/15654
// 5888KB	36ms
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
