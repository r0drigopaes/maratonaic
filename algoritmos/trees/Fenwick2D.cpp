#include <bits/stdc++.h>
using namespace std;
#define LSB(x) x&(-x)
// Árvore de Fenwick 2D
struct Fw
{
	vector<vector<int> > ft;
	Fw( vector< vector<int> > & v )
	{
		// Construção N*M*lg(N)*lg(M)
		ft.resize(v.size()+1, vector<int>(v[0].size()+1,0));
		for (int i = 0; i < v.size() ; ++i)
			for (int j = 0; j < v[0].size() ; ++j)
				update(i+1,j+1,v[i][j]);

	}
	// lg(N)*lg(M)
	void update( int x, int y, int v ) {
		while( x < ft.size() ) {
			int yy = y;
			while( yy < ft[0].size() ){
				ft[x][yy] += v;
				yy += LSB(yy);
			}
			x += LSB(x);
		}
	}
	// lg(N)*lg(M)
	int query(int x, int y){
		int sum = 0;
		int yy = y, xx = x;
		while( xx ) {
			yy = y;
			while( yy ){
				sum += ft[xx][yy];
				yy -= LSB(yy);
			}
			xx -= LSB(xx);
		}
		return sum;
	}
	// lg(N)*lg(M)
	int query( int bx , int by , int ex , int ey ){
		return query(ex,ey) - query(bx-1,ey) - query(ex,by-1) + query(bx-1,by-1);
	}
};

int main(int argc, char const *argv[])
{
	vector< vector<int> > v;
	int n;
	cin >> n;
	v.resize( n , vector<int>(n,0) );
	// The Huxley 538
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];

	Fw fw = Fw(v);
	// Encontrar a submatriz de soma máxima 
	int ans = -(1<<20);
	for (int i = 1; i <= n ; ++i)
		for (int j = 1; j <= n ; ++j)
			for (int k = i; k <= n; ++k)
				for (int l = j; l <= n; ++l)
					ans = max( ans, fw.query(i,j,k,l) );

	cout << ans << endl;

	return 0;
}