#include <iostream>
#include <set>
#include <string>
using namespace std;

string S1, S2;
void getSubSequence(string s, string fs, int i, set<string> &set);
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> S1 >> S2;
	
	set<string> set1;
	set<string> set2; 
	for(int i=0;i<S1.length();i++){
		set1.insert(string(1,S1[i]));
		getSubSequence(S1, string(1,S1[i]), i+1, set1);
	}
	for(int i=0;i<S2.length();i++){
		set2.insert(string(1,S2[i]));
		getSubSequence(S2, string(1,S2[i]), i+1, set2);
	}
	
	int lcs = 0;
	for(set<string>::iterator it=set1.begin();it!=set1.end();++it){
		if(set2.find(*it) != set2.end()){
			if((*it).length()>lcs)
				lcs = (*it).length();
		}	
	}
	
	cout << lcs ;
	
	return 0;
}

void getSubSequence(string s, string fs, int addIndex, set<string> &set){
	if(addIndex>=s.length()) return;
	
	string result;
	for(int j=addIndex;j<s.length();j++){
		result = fs+string(1, s[j]);
		set.insert(result);
		getSubSequence(s, result, j+1, set);
	}
}


/* https://www.acmicpc.net/problem/9251 메모리 초과 
ACAYKP
CAPCAK

4
*/
