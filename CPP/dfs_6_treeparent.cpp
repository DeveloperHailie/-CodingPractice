#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int N;
vector<vector<int> > network(100010);
vector<int> parent(100010); //parent[child]=parent;
void dfs(int n1){	
	for(int i=0;i<network[n1].size();i++){
		int n2 = network[n1][i];
		if(parent[n2]!=0)	continue; 
		parent[n2]=n1;
		dfs(n2);
	}
}

int main(){
	
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> N;
	int n1,n2;
	for(int i=0;i<N-1;i++){
		cin >> n1 >> n2 ;
		network[n1].push_back(n2);
		network[n2].push_back(n1);
	}
	
	parent[1] = true;
	dfs(1);

	for(int i=2;i<=N;i++){
		cout << parent[i] << "\n";
	}
	
	return 0;
}

/*
https://www.acmicpc.net/problem/11725
12492KB	44MS
*/
