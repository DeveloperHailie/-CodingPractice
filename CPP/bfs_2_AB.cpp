#include <iostream>
#include <queue>
using namespace std;


long long A,B;
struct st {
	long long value, count;
};
queue<struct st> q;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> A >> B;
	
	q.push({A, 1});
	
	long long nv1, nv2;
	long minCount = -1;
	while(!q.empty()){
		struct st c = q.front();
		q.pop();
		
		nv1 = c.value*2;
		nv2 = c.value*10+1;
	
		if(nv1<B){
			q.push({nv1, c.count+1});
		}
		if(nv2<B){
			q.push({nv2, c.count+1});
		}
		if(nv1==B || nv2==B){
			minCount = c.count+1;
			break;
		}
	}
	
	cout << minCount ;
	
	return 0;
}
/*
https://www.acmicpc.net/problem/16953
2 162
5

A, B (1 ¡Â A < B ¡Â 10^9) => long long type!!
*/
