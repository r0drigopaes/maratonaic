#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 10;
int p[MAX], d[MAX];
vector<int>adj[MAX];
int di;
int root(int x) {
	if(p[x] == x) return x;
	return p[x] = root(p[x]);
}

void merge(int x, int y){
	x = root(x);
	y = root(y);
	p[x] = y;
}
int bu;
int go(int u, int k = 0, int pa = -1) {
	if(k > di)bu = u, di = k;
	for(auto v : adj[u])if(v - pa) go(v, k+1, u);
}
int main() {
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 0; i < n; ++i)p[i] = i;
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
		merge(u-1, v-1);
	}
	for(int i = 0; i < n; ++i){
		if(d[root(i)] != 0)continue;
		di = -1;
		go(root(i));
		go(bu);
		d[root(i)] = di;
	}
//	for(int i = 0; i < n; ++i)printf("%d %d %d\n", i, root(i), d[root(i)]);
	for(int i = 0; i < q; ++i){
		int op, u, v;
		scanf("%d", &op);
		if(op == 1){
			scanf("%d", &u);
			--u;
			printf("%d\n", d[root(u)]);
		}else {
			scanf("%d %d", &u, &v);
			--u, --v;
			int d1 = d[root(u)];
			int d2 = d[root(v)];
			if(root(u) == root(v))continue;	
			merge(u, v);
			int d3 = 1 + (d1+1)/2 + (d2+1)/2;
			d[root(u)] = max(d1, max(d2, d3));
			//printf("%d %d %d\n", u+1, v+1, d[root(u)]);
		}
	}
	return 0;
}

