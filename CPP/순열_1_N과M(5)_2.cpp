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
			temp.push_back(list[i]); //�������� 0~(r-1)������  
		}
		result.insert(temp); // �ڵ����� ���������̳� ������������ ����
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
	// ���� nCr (1)
	 
	for(int i=M;i<N;i++){
		mask[i]=1; //N-M�� 1�� ä���, 0�� ���� 
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
	
	// ���� nCr (2)
	
	for(int i=0;i<M;i++){
		mask[i]=1; //M�� 1�� ä���, 1�� ���� 
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
	
	// ���� nPn
	do{
		for(int i=0;i<N;i++){
			cout << list[i]	<< " ";	
		}
		cout << endl;
	}while(next_permutation(list,list+N)); 
	

*/
