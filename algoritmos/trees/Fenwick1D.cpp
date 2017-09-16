#include <bits/stdc++.h>
using namespace std;
#define LSB(x) x&(-x)
struct Fw
{
	vector<int> ft;
	Fw( vector<int> & v )
	{
		// Construção N*lg(N)
		ft.resize(v.size()+1,0);
		for (int i = 0; i < v.size() ; ++i)
			update(i+1,v[i]);		
	}
	// lg(N)
	void update( int k , int v ) {
		while( k < ft.size() ) {
			ft[k] += v;
			k += LSB(k);
		}
	}
	// lg(N)
	int query(int r, int l){
		return query(r) - query(l);
	}
	// lg(N)
	int query(int r){
		int sum = 0;
		while( r ){
			sum += ft[r];
			r -= LSB(r);
		}
		return sum;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> v;
	v.push_back(3);
	v.push_back(7);
	v.push_back(2);
	v.push_back(1);
	v.push_back(5);
	Fw fw = Fw(v);
	for (int i = 0; i < v.size() ; ++i)
		cout << fw.query(i+1) - fw.query(i) << endl;

	return 0;
}