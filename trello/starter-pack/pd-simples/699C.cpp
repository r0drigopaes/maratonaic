#include <bits/stdc++.h>

using namespace std;
#define MAX 105
int a[MAX];
int n;

int DP[MAX][MAX];

int dp(int last, int i){
    if (DP[last][i] != -1) return DP[last][i];
    int best = 0;
    int clast = last;
    for (int j=i ; j < n ; j++){
        if (clast == 2){
            if (a[j] == 1) clast = 0;
            else if (a[j] == 2) clast = 1;
            else if (a[j] == 3){
                best = best + min(dp(0,j+1), dp(1,j+1));
                return DP[last][i] = best;
            }
            else best += 1;
        }
        else if (clast == 0){
            if (a[j] == 2 || a[j] == 3) clast = 1;
            else{
                best += 1;
                clast = 2;
            }
        }
        else if (clast == 1){
            if (a[j] == 1 || a[j] == 3) clast = 0;
            else{
                best += 1;
                clast = 2;
            }
        }
    }
    return DP[last][i] = best;
}

int main(){
    cin >> n;
    memset(DP, -1, sizeof(DP));
    for (int i = 0 ; i < n ; i++) scanf("%d", a+i);
    printf("%d\n",dp(2,0));
    return 0;
}
