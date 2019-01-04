#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
vector <double> ff, rr, divi;
int main()
{
	int f, r, i;
	double d, ma, me;
	while (cin>>f, f)
	{
		ff.clear(); rr.clear(); divi.clear();
		cin>>r;
		for (i=0; i<f; ++i)
		{
			cin>>d;
			ff.push_back(d);
		}

		for (i=0; i<r; ++i)
		{
			cin>>d;
			rr.push_back(d);
		}
		
		for (auto d1:ff)
			for (auto d2:rr)
				divi.push_back(d2/d1);
		ma=0.0;
		//for (auto k:divi)
		//	cout<<k<<" ";
		//cout<<endl;
		sort(divi.begin(), divi.end());
		for (i=1; i<divi.size(); ++i)
		{
			//cout<<divi[i]/divi[i-1]<<" ";
			ma=max(ma, divi[i]/divi[i-1]);
			//ma=max(ma, divi[i]/divi[i-1	]);
		}
		//cout<<endl;
		//me=*min_element(divi.begin(), divi.end());
		//ma=*max_element(divi.begin(), divi.end());
		printf("%.2lf\n", ma);
	}
	return 0;
}