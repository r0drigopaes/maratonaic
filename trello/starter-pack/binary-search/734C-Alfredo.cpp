#include <bits/stdc++.h>
using namespace std;

vector< pair<int,int> > potions; 
vector< pair<int,int> > potions2;

long long lower( long long v )
{
	long long begin = 0, end = potions2.size()-1;
	long long mid;
	long long ans = -1;
	while( begin <= end )
	{
		mid = (begin+end)/2;
		if( potions2[mid].first <= v )
		{
			begin = mid+1;
			ans = max(ans,mid);
		}
		else
		{
			end = mid-1;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	long long N;
	long long M, K;
	long long T, MP;
	cin >> N;
	cin >> M >> K;
	cin >> T >> MP;
	potions.resize(M);
	potions2.resize(K);
	for (int i = 0; i < M; ++i)
		cin >> potions[i].second;
	for (int i = 0; i < M; ++i)
		cin >> potions[i].first;

	for (int i = 0; i < K; ++i)
		cin >> potions2[i].second;
	for (int i = 0; i < K; ++i)
		cin >> potions2[i].first;

	long long ans = T * N;

	for (int i = 0; i < potions.size() ; ++i)
	{
		if( potions[i].first <= MP )
		{
			ans = min(ans, potions[i].second*N);
			int t = lower( MP-potions[i].first );
			//cout << "# " << t << " -- R " << MP-potions[i].first << " --- F --- " << potions2[t].first << endl;
			if( t >= 0 ) ans = min(ans,max((N-potions2[t].second),0LL)*(potions[i].second));
		}
	}

	int t = lower( MP );
	if( t >= 0 ) ans = min(ans,max((N-potions2[t].second),0LL)*(T));

	cout << ans << endl;
	return 0;
}