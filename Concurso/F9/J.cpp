#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, d, sum, a;
	cin>>n;
	vector <int> v;
	for (int caso = 1; caso <= n; ++caso)
	{
		cin>>m;
		v.clear();
		d = max(m/2, 1);
		while (m--)
		{
			cin>>a;
			v.push_back(a);
		}
		sort ( v.begin(), v.end() );
		d = (int)(v.size())-1 -d;
		sum = 0;
		int j;
		for ( j = v.size()-1, cout<<j<<" "<<d<<endl; j > d ; --j)
			sum += v[j];
		printf("Spree #%d: %d\n", caso, sum);
	}
	return 0;
}