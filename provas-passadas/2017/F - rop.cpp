#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000;
bool mycomp(const int &a,const int &b){
	return a > b;
}
int a[MAX];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i)scanf("%d", a+i);
	sort(a, a+n, mycomp);
	int ans = 0;
	for(int i = k; i < n; ++i)ans+= (a[i] == a[k-1]);
	printf("%d\n", ans+k);
	return 0;
}
