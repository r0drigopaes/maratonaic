#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
char s[MAX];
int getsum(int x, int y){
	int res = x+y;
	if(res >= 10) return (res/10) + (res%10);
	return res;
}
int main() {
	scanf("%s", s);
	int sum = 0;
	int tam = 0;
	for(int i = 0; s[i]; ++i){
		++tam;
		sum = getsum(sum, s[i] - '0');
	} 
	if(sum == 3 || sum == 6 || sum == 9)puts("0");
	else {
		if(s[tam-1] != '9'){
			sum = 0;
			s[tam-1]++;
			for(int i = 0; s[i]; ++i){
				sum = getsum(sum, s[i] - '0');
			} 
			if(sum == 3 || sum == 6 || sum == 9)puts("2");
			else puts("1");
		}else {
			sum = 0;
			s[tam-1]--;
			for(int i = 0; s[i]; ++i){
				sum = getsum(sum, s[i] - '0');
			} 
			if(sum == 3 || sum == 6 || sum == 9)puts("1");
			else puts("2");
		}
	}
	return 0;
}