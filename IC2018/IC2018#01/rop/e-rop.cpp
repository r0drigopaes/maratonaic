#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
long long a[MAX], b[MAX];
int n, m;
long long f(long long det) {
	long long ans = 0;
	for(int i = 0; i < n; ++i)if(a[i] < det)ans+=abs(det-a[i]);
	for(int i = 0; i < m; ++i)if(b[i] > det)ans+=abs(det-b[i]);
	return ans;
}
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)scanf("%lld", a+i);
	for(int i = 0; i < m; ++i)scanf("%lld", b+i);
	long long ans = 1LL * 1e18, lf = 1, rg = 1LL *1e9;

	for(int i = 0; i < 200; ++i) {
		long long mid1 = lf + (rg-lf) / 3;
		long long mid2 = rg - (rg-lf) / 3;
		ans = min(ans, f(mid1));
		ans = min(ans, f(mid2));
		if(f(mid1) < f(mid2))rg = mid2;
		else lf = mid1;
	}

	printf("%lld\n", ans);
	return 0;
}
