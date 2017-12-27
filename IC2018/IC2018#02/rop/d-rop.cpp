#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3fll;
template<class T> T abs(T x) { return x > 0 ? x : -x;}
template<class T>  inline T sqr(T x) {return x*x; }
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define rep(i, a, n) for(int i=a; i <n; i++)
#define repn(i, a, n)for(int i = a; i <=n; i++)
#define per(i, a, n) for(int i=n-1; i>=a; i--)
#define vrep(it, c) for(__typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define mset(x, y) memset(x, y, sizeof (x))
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define uniq(c) (c).resize(unique(all(c)) - (c).begin())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<vector<ll> >matrix;
const int MAX = 110;
const int mod = 1e9 + 7;
matrix C, iden;
int n = 2;
matrix mul(const matrix &A, const matrix &B){ // A*B
	rep(i, 0, n){
		rep(j, 0, n){
			C[i][j] = 0;
			rep(k, 0, n){
				C[i][j]+=A[i][k]*B[k][j];
			}
			C[i][j]%=mod;
		}
	}
	return C;
}
matrix mpow(matrix &A, ll power){ // A ^ power
	int K = n;
	rep(i, 0, K)rep(j, 0, K)iden[i][j] = (i == j);
	while(power){
		if(power&1) iden = mul(iden, A);
		A = mul(A, A);
		power >>= 1;
	}
	return iden;
}
int main(){
	matrix m;
	long long l;	
	scanf("%lld", &l);
	iden.assign(2, vector<ll> (2, 0));
	C.assign(2, vector<ll>(2, 0));
	m.assign(2, vector<ll>(2, 0));
	m[0][1] = 3;
	m[1][0] = 1;
	m[1][1] = 2;
	m = mpow(m, l);
	printf("%lld\n", m[0][0]);

	return 0;
}
