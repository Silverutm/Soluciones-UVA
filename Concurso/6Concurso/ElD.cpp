#include <iostream>
using namespace std;
int main()
{
	int t, i, j, parcial, k, n;
	cin>>t;
	while (t--)
	{
		cin>>n;
		cout<<"# "<<n<<":\n";
		for (i=1; i<=n; ++i)
		{
			if ( (n%i)!=0 ) continue;
			parcial = n/i;
			for (j=i; j<=parcial; ++j)
			{
				if ((parcial%j)!=0) continue;
				k=parcial/j;
				if (j>k) continue;
				cout<<"("<<i<<","<<j<<","<<k<<")"<<endl;
			}
		}
		//cout<<"algo";
	}
	return 0;
}