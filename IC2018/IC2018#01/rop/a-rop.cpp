#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
int n;
double a[MAX], b[MAX];
double calc(double x) {
	for(int i = 0; i < n; ++i)b[i] = a[i] - x;
	double ans1 = 0, ans2 = 0, sum = 0, sum2 = 0;
	for(int i = 0; i < n; ++i){
		ans1 = max(ans1, sum);
		ans2 = min(ans2, sum2);
		sum+=b[i];
		sum2+=b[i];
		sum = max(sum, 0.);
		sum2 = min(sum2, 0.);
	}
	ans1 = max(ans1, sum);
	ans2 = min(ans2, sum2);
	return max(ans1, abs(ans2));
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)scanf("%lf", a+i);
 	double lf  = -1e10;
 	double rg  = 1e10;
 	for(int i = 0; i < 400; ++i) {
 		double md1 = (lf*2+rg)/3;
 		double md2 = (lf+2*rg)/3;
 		if(calc(md1) < calc(md2))rg = md2;
 		else lf = md1;
 	}
 	printf("%.20lf", calc(lf));
	return 0;
}
