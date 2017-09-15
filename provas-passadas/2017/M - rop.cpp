#include<bits/stdc++.h>
using namespace std;
int a[3];
int main() {
	for(int i = 0; i < 3; ++i) scanf("%d", a+i);
	int res = INT_MAX;
	for(int i = 0; i < 3; ++i){
		int x = 2*abs(i - ((i+1)%3)) * a[(i+1)%3];
		int y = 2*abs(i - ((i+2)%3)) * a[(i+2)%3];
		res = min(res, x + y);
	}
	printf("%d\n", res);
	return 0;
}