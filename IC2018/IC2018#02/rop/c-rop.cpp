#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i=a; i <n; i++)
#define sqrt(x) sqrt(abs(x))
typedef long long ll;
typedef pair<int, int> ii;
const int mod = 1e9 + 7;
const int MAX = 16;
struct Matrix{
public:
    int n, m;
    ll a[MAX][MAX];
    Matrix(int _n = 0, int _m = 0){
        n = _n, m = _m;
        memset(a, 0, sizeof a);
    }
    Matrix operator * (Matrix &R) const {
        Matrix res(n, R.m);
        rep(i, 0, n)rep(j, 0, R.m)rep(k, 0, m){
            res.a[i][j] = (res.a[i][j] + a[i][k] * R.a[k][j])%mod;
        }
        return res;
    }
};
Matrix mpow(Matrix &a, ll power){
    Matrix iden(a.n, a.n);
    rep(i, 0, a.n)iden.a[i][i] = 1;
    for( ; power ; power >>= 1){
        if(power&1)iden = iden*a;
        a = a*a;
    }
    return iden;
}
long long v[20], v2[20];
int main() {
    int nn;
    long long a, b, c, k;
    scanf("%d %lld", &nn, &k);

    v[0] = 1;

    for(int N = 0; N < nn; ++N) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if(b > k)b = k;
        ++c;
        Matrix m(c, c);
        for(int i = 0; i < c; ++i){
            for(int j = 0; j < c; ++j) {
               m.a[i][j] = (abs(i-j) <= 1);
            }
        }
        Matrix m2 = mpow(m, b-a);
        for(int i = 0; i < c; ++i){
            v2[i] = 0;
            for(int j = 0; j < c; ++j){
                v2[i] = (v2[i] + m2.a[j][i] * v[j])%mod;
            }
        }
        for(int i = c; i < 16; ++i)v2[i] = 0;
        for(int i = 0; i < 16; ++i)v[i] = v2[i];
    }
    printf("%lld\n", v[0]);
    return 0;
}
