#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 1;
void fail() {
	printf("Incorrect sequence\n"); 
	exit(0);
}
int main() {
	int n, k, x;
	char c;
	scanf("%d %d", &n, &k);
	vector<vector<int> >chain(k);

	for(int i = 0; i < n; ++i) {
		scanf(" %c", &c);
		x = oo;
		if(c != '?'){
			ungetc(c, stdin);
			scanf("%d", &x);
		}
		chain[i%k].push_back(x);
	}

	for(auto &ch : chain) {
		int sz = (int)ch.size();
		if(!sz)continue;
		int lf = 0;
		while(lf < sz && ch[lf] == oo) ++ lf;
		if(lf == sz) {
			lf/=2;
			lf*=-1;
			for(int &el : ch) el = lf++;
			continue;
		}

		if(lf > 0) {
			if(ch[lf] > (lf-1)/2) {
				int val = -lf/2;
				for(int i = 0; i < lf; ++i){
					ch[i] = val++;
				}
			}else {
				for(int i = lf-1; i>=0; --i){
					ch[i] = ch[i+1]-1;
				}
			}
		}

		int prev = ch[lf];

		while(lf < sz-1) {
			int rg = lf+1;
			while(rg < sz && ch[rg] == oo)++rg;
			int tam = rg-lf-1;
			if(rg == sz) {
				if(prev < -(tam-1)/2) {
					int val = tam/2;
					for(int i = sz-1; i > lf; --i){
						ch[i] = val--;
					}
				} else {
					for(int i = lf+1; i < sz; ++i) {
						ch[i] = ch[i-1]+1;
					}
				}
				break;
			}
			tam/=2;
			if(prev + rg-lf > ch[rg]) fail();
			if(prev >= -tam) {
				for(int i = lf+1 ; i < rg; ++i) {
					ch[i] = ch[i-1]+1;
				}
			} else if(ch[rg] <= tam) {
				for(int i = rg-1; i > lf; --i) {
					ch[i] = ch[i+1]-1;
				}
			} else {
				int val = -tam;
				for(int i = lf+1; i < rg; ++i)ch[i] = val++;
			}
			lf = rg;
			prev = ch[rg];
		}
	}

	for(int i = 0, x = 0, y = 0; i < n; ++i) {
		printf("%d ", chain[x][y]);
		++x;
		if(x == k) x = 0, ++y;
	}
	puts("");
	return 0;
}
