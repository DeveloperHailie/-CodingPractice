#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const string score[10] = {"A+","A0","A-","B+","B0","B-","C+","C0","C-","D0"};
bool compare(pair<int,double> a,pair<int,double> b){
	return a.second > b.second;
}
int main(){
	int tC;
	vector<pair<int,double> > v;
	cin >> tC;
	for(int t=1;t<=tC;t++){
		int n,k;
		cin >> n >> k;
		v.assign(n,pair<int,double>(0,0));
		double a,b,c,sum;
		for(int i=0;i<n;i++){
			cin >> a >> b >> c;
			sum = a*0.35 + b*0.45 + c*0.2;
			v.push_back(pair<int,double>(i+1,sum));
		}
		sort(v.begin(),v.end(),compare);
		cout << "#" << t << " ";
		int count = 0;
		for(int i=0;i<v.size();i++){
			if(v[i].first==k)
				break;
			count++;
		}
		cout << score[count/(n/10)] << "\n";	
	}
	return 0;
}
