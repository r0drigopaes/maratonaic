#include <bits/stdc++.h>
using namespace std;
bool ispal(string s){
	int lf = 0;
	int rg = s.size()-1;
	while(lf <= rg){
		if(s[lf] != s[rg])return false;
		++lf;
		--rg;
	}
	return true;
}
int main(){
	string s;
	cin >> s;
	for(int i = 'a'; i <= 'z'; ++i){
		for(int j = 0; j < s.size(); ++j){
			string ss = "";
			for(int k = 0; k < s.size(); ++k){
				if(k == j)ss+= (char)i;
				ss+= s[k];
			}
			if(ispal(ss)){
				cout << ss << endl;
				exit(0);
			}
		}
		string ss = s;
		if(ispal(ss + (char)i) ){
			cout << ss + (char)i << endl;
			exit(0);
		}
	}
	puts("NA");
	return 0;
}
