#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int  t, q, k,i;
	vector < pair<int, int>  > vectorini, mivector;
	string s;
	while (cin>>s and s!="#" )
	{
		cin>>q>>t;
		vectorini.push_back(make_pair(t, q) );
	}
	cin>>k;
	for ( auto v:vectorini )
		for (i=1; i<=k; ++i)
			mivector.push_back( make_pair(v.first*i, v.second) );
	sort(mivector.begin(),mivector.end());
	for (i=0; i<k; ++i)
		cout<<mivector[i].second<<endl;
	return 0;
}