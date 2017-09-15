#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int pd[51][MAX];
const int mod = 1e9 + 7;
int main() {
	int t, n, m, ans = 0;;
	scanf("%d %d %d", &t, &n, &m);
	for(int i = n; i <= m; ++i)pd[0][i] = 1;
	for(int i = 1; i < t; ++i){
		for(int j = n; j <=m; ++j){
			pd[i][j] = (pd[i-1][j-1]+pd[i-1][j+1])%mod;
		}
	} 
	for(int i = n; i <=m; ++i){
		ans = (ans+pd[t-1][i])%mod;
	}
	printf("%d\n", ans);

	return 0;
}