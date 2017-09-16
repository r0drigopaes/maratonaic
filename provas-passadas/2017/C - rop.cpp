#include <bits/stdc++.h>
using namespace std;

long long gdc(long long a, long long b){return b == 0? a: gdc(b, a%b); }
long long lcm(long long a, long long b){return a*(b/gdc(a, b));}


int main() {
	long long n, l;
	long long ans = 1;
	long long best, cur, tot = 1;
	scanf("%lld %lld", &n, &l);
	for(long long i = 0; i < n; ++i){
		scanf("%lld", &cur);
		tot = lcm(tot, cur);
	}
	best = tot;
	for(long long i = 2; i <= l; ++i){
		long long mm = lcm(tot, i);
		if(mm > best && mm <= l){
			best = mm;
			ans = i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}