#include <bits/stdc++.h>
using namespace std;
long long tam;
vector<long long>primes;
bitset<10000010>bs;
long long fastExp(long long a, long long b) {
    long long ans = 1ll;
    while(b != 0) {
            if(b%2ll == 1ll)ans*=a;
            a*=a;
            b /= 2ll;
    }
    return ans;
}
void sieve(int upperbound) {
	tam = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(long long i = 2; i <= tam; ++i) if(bs[i]) {
		for(long long j = i*i ; j <= tam; j+=i)bs[j] = 0;
		primes.push_back(i);
	}
}
bool isPrime(long long x){
	if(x <= tam) return bs[x];
	for(int i = 0; i < primes.size(); ++i)
		if(x%primes[i] == 0)return false;
	return true;
}
int main() {
	sieve(10000000ll);
	long long n;
	scanf("%lld", &n);
	long long p = 0;
	for(int i = 0; i < primes.size(); ++i) {
		if(n%primes[i] == 0){
			++p;
			while(n%primes[i] == 0)n/=primes[i];
		}
	}
	if(n > 1ll)++p;
	printf("%lld\n", fastExp(2, p)-p-1ll);
	return 0;
}