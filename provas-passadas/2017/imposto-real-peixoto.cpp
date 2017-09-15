#include <bits/stdc++.h>

using namespace std;

#define MAX 10005

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int n,k;
int debt[MAX];
vpii depth;
int check[MAX];
int father[MAX];
int weight[MAX];
vpii adj[MAX];
int ans = 0;

void find_depth(int v, int curdepth, int fat){
    father[v] = fat;
    depth.push_back(make_pair(curdepth,v));
    for (auto x : adj[v]){
        if (father[x.first]) continue;
        weight[x.first] = x.second;
        find_depth(x.first,curdepth+1,v);
    }
}
int main(){
    int a,b,c;
    scanf("%d %d",&n,&k);
    for (int i = 1; i <= n; i++) scanf("%d", &debt[i]);
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    find_depth(1,0,1);
    sort(depth.begin(),depth.end());
    for(int i = depth.size()-1 ; i >= 0; i--){
        int times = (debt[depth[i].second]/k) + ((debt[depth[i].second]%k == 0) ? 0 : 1); 
        ans = ans + (2*weight[depth[i].second])*times; 
        debt[father[depth[i].second]] += debt[depth[i].second];
    }
    printf("%d\n",ans);
    return 0;
}
