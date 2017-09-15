#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
int escalas[12][8];
int dx[8] = {2, 2, 1, 2, 2, 2, 1};
string seq[12] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
vector< set<int> > v;
int a[MAX];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)scanf("%d", a+i);
	for(int i = 0; i < n; ++i)a[i] = (a[i]-1)%12;
	for(int i = 0; i < 12; ++i){
		set<int>st;
		st.insert(i);
		int x = i;		
		for(int j = 0; j < 8; ++j){
				x = (x+dx[j])%12;
				st.insert(x);
		}
		v.push_back(st);
	}
	set<int>mySq;
	for(int i = 0; i < n; ++i)mySq.insert(a[i]);
	for(int i = 0; i < v.size(); ++i){
		bool ok = true;		
		for(auto now : mySq){
			if(!v[i].count(now)){
				ok = false;
				break;
			}
		}
		if(ok){
			printf("%s\n", seq[i].c_str());
			return 0;		
		}
	}
	printf("desafinado\n");
	return(0);
}
