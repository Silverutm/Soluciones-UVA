#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int n,m,c,t;
	long long a;
	vector<long long> cabezas;
	vector<long long> caballeros;
	while(cin>>n && cin>>m && m+n!=0)
	{
		if(n<=m)
		{
			c=0;
			cabezas.clear();
			caballeros.clear();
			for (int i=0; i<n; i++)
			{
				cin>>a;
				cabezas.push_back(a);
			}
			for (int i=0; i<m; ++i)
			{
				cin>>a;
				caballeros.push_back(a);
			}
			sort(cabezas.begin(), cabezas.end());
			sort(caballeros.begin(), caballeros.end());
			t=0;
			for(int i=0; i<n; i++)
				for (int j = 0; j< m; ++j)
				{
					if(caballeros[j]>=cabezas[i])
					{
						t+=caballeros[j];
						c++;
						caballeros[j]=-1;
						cabezas[i]=1000000000000;
					}
				}
			if (c==n)
				cout<<t;
			else
				cout<<"Loowater is doomed!";

		}
		else
		{
			for (int i=0; i<n+m; i++)
				cin>>a;
			cout<<"Loowater is doomed!";
		}
		cout<<endl;
	}
	return 0;
}