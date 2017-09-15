#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 10;
int a[MAX], vstd[MAX];
pair<int, int>pai[MAX];
vector< pair<int, int> >dep;
bool mycomp(pair<int,int> &p1, pair<int, int>&p2) {
	return p1.first > p2.first;
}
vector< pair<int, int> >adj[MAX];
void dfs(int x, int depth = 0){
	vstd[x] = 1;
	dep.push_back(make_pair(depth, x));
	for(auto yy : adj[x]){
		int y = yy.first;
		int d = yy.second;
		if(!vstd[y]){
			pai[y].first = x;
			pai[y].second = d;
			dfs(y, depth+1);
		}
	}
}
int main() {
	int n, m, u, v, w;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%d", a+i);
	}
	for(int i = 0; i < n-1; ++i){
		scanf("%d %d %d", &u, &v, &w);
		--u,--v;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	dfs(0);
	sort(dep.begin(), dep.end(), mycomp);
	long long ans = 0;
	for(int i = 0; i < dep.size(); ++i){
		if(dep[i].first == 0)continue;
		int x = dep[i].second;
		int quant = (a[x]/m);
		if(a[x]%m != 0)++quant;
		ans += 2ll*quant*pai[x].second;
		a[pai[x].first]+=a[x];  
	}
	printf("%lld\n", ans);
	return 0;
}
