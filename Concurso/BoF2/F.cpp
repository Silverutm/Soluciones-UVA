#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n,q,r,aux,a,b;
	vector<int> hermanos;
	vector < pair<int,int> > ph;
	pair <int, int> auxph;
	cin>>n;
	aux=n;
	while(n--)
	{
		cin>>a>>b;
		auxph.first=a;
		auxph.second=b;
		ph.push_back(auxph);
		hermanos.push_back(a);
		hermanos.push_back(b);
	}
	sort(hermanos.begin(),hermanos.end());
	cin>>q;
	while(q--)
	{
		cin>>r;
		for (int i = 0; i < aux; ++i)
		{
			if (r==ph[i].first)
			{
				for (int j = 0; j <aux*2; ++j)
				{
					if (ph[i].second==hermanos[j])
					{
						cout<<j+1<<endl;
					}
				}
			}
			if (r==ph[i].second)
			{
				for (int j = 0; j <aux*2; ++j)
				{
					if (ph[i].first==hermanos[j])
					{
						cout<<j+1<<endl;
					}
				}
			}
		}
	}
	
	return 0;
}