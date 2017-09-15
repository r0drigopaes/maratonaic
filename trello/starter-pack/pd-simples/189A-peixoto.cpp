#include <bits/stdc++.h>

using namespace std;
#define MAX 100000

int len[3];
int v[MAX];

int dp(int n){
    if (n == 0) return 0;
    if (v[n] != -1) return v[n];
    int best = 1;
    int f = 1;
    for(int i = 0 ; i < 3 ; i++){
        if (n == len[i]) f = 0;
        if (n-len[i] >= 0) best = max(best, 1 + dp(n-len[i]));
    }
    if (f && best == 1) return v[n] = -100000;
    return v[n] = best;
}

int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    memset(v, -1, sizeof(v));
    len[0] = a;
    len[1] = b;
    len[2] = c;
    printf("%d\n",dp(n));
    return 0;
}
