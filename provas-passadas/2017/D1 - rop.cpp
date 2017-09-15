#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
vector<long long>a;
long long q = 0;
long long p = 0;
long long n, _sieve_size;
bitset<11000010>bs;
vector<int>primes;
void sieve(long long upperbound){
	_sieve_size = upperbound+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(long long i = 2; i <= _sieve_size; ++i)if(bs[i]){
		for(long long j = i*i; j <= _sieve_size; j+=i)bs[j] = 0;
		primes.push_back((int)i);
	}
}
bool isPrime(long long N){
	if(N <= _sieve_size)return bs[N];
	for(int i = 0; i < primes.size(); ++i){
		if(N%primes[i] == 0)return false;
	}
	return true;
}
bool check(long long x){
	if(isPrime(x) || x == 1ll)return false;
	int cnt = 0;
	for(int i = 0; i < primes.size(); ++i){
		if(x == 1ll)return true;
		if((x < primes[i]) )return false;
		if((x%primes[i]) == 0){
			x/=(long long)primes[i];
			++cnt;
			if((x%primes[i]) == 0)return false;		
		}
	}	
	return (x == 1ll  || (cnt && isPrime(x)));
}
int main() {
	long long res = 0;

	scanf("%lld", &n);
	for(long long i = 2; i*i <= n; ++i){
		if(n%i == 0){
			a.push_back(n/i);
			if(i != (n/i)){
				a.push_back(i);
			}
		}
	}
	sieve(min(n, 10000000ll)	);
	long long ans = 0;
	for(int i = 0; i < a.size(); ++i){
		if(check(a[i])){
			++ans;
		}
	}
	ans+=check(n);
	printf("%lld\n", ans);
	return 0;
}
