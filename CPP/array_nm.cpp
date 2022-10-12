#include <iostream>
using namespace std;

int list[100][100];
int main(){
	int n,m;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << list[i][j];
		}
		cout << endl;
	}
	return 0;
}
