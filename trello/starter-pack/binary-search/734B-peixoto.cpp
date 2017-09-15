#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001
int n,m,k;
int x,s;
int a[MAX], b[MAX], c[MAX], d[MAX];

long long int solve(int cost,int i,long long int ans){
    int lo = 0;
    int hi = k;
    int up = 0;
    while (lo <= hi) {
        int mid = (hi+lo)/2;
        if (d[mid] > cost) {
            hi = mid -1;
        } else {
            up = mid;
            lo = mid + 1;
        }
    }
    ans = min(ans,1LL * a[i]*(n-c[up]));
    return ans;
}

int main(){
    cin>>n>>m>>k;
    cin>>x>>s;
    long long int ans = 1LL*x*n;
    a[0] = x;
    b[0] = 0;
    c[0] = 0;
    d[0] = 0;
    for (int i = 1; i <= m; i++) scanf("%d",&a[i]);
    for (int i = 1; i <= m; i++) scanf("%d",&b[i]);
    for (int i = 1; i <= k; i++) scanf("%d",&c[i]);
    for (int i = 1; i <= k; i++) scanf("%d",&d[i]);
    for (int i = 0; i <= m; i++) {
        int cost = s-b[i];
        if (cost > 0) {
            ans = solve(cost,i,ans);
        } else if (cost == 0) {
            ans = min(ans,1LL * a[i]*n);
        }    
    }
    cout << ans << endl;
    return 0;
}
