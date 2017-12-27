#include <bits/stdc++.h>
using namespace std;
int n, c4, c5, c3, s;
int I, J, K;
int main() {
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		c3+= x == 3;
		c4+= x == 4;
		c5+= x == 5;
	}
	int ans = 1e9 + 10;
	for(int i = s/n; i>= 0; --i) {
		for(int j = (s - c3*i)/(n-c3); j >= i; --j) {
			int tot3 = i*c3;
			int tot4 = j*c4;
			int k = (s - tot3 - tot4)/c5;
			int tot5 = k*c5;
			if(tot5-tot4 >= ans)break;
			if(tot3 + tot4 + tot5 == s && ans > abs(tot3-tot4)+abs(tot4-tot5)){
				ans = abs(tot3-tot4)+abs(tot4-tot5);
				I = i;
				J = j;
				K = k;
			}
		}
	}
	if(ans != 1e9 + 10)printf("%d %d %d\n", I, J, K);
	else puts("-1");

	return 0;
}
