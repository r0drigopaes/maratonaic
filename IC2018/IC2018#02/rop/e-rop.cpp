#include <bits/stdc++.h>
using namespace std;

int fexp(int x, int n, int mod){
	int ans = 1;
	while(n != 0){
		if(n&1)ans = (ans*x)%mod;
		x = (x*x)%mod;
		n >>= 1;
	}
	return ans;
}
int fexp(int x, string ns, int mod){
	x%= mod;
	int ans = 1%mod;
	int now = x;
	for(int i = (int)ns.size() - 1; i >= 0; --i){
		ans = (ans * fexp(now, ns[i] - '0', mod)) % mod;
		now = fexp(now, 10, mod);
	}
	return ans;
}
int main(){
	string s;
	cin >> s;
	int res = fexp(1, s, 5) + fexp(2, s, 5) + fexp(3, s, 5) + fexp(4, s, 5);
	res%=5;
	printf("%d\n", res);
	return 0;
}
