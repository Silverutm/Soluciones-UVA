#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int conjunto[1009], sumas[1000009];

int main()
{
	int n, m, q, i,res, caso=1, k, l, j;
	while (cin>>n, n)
	{
		for (i=0; i<n; ++i)
			cin>>conjunto[i];

		for (k=i=0; i<n; ++i)
			for (j=i+1; j<n; ++j)
				if (conjunto[i]!=conjunto[j])
					sumas[k++]=conjunto[i]+conjunto[j];
		sort(sumas, sumas+k);
		cin>>m;
		cout<<"Case "<<caso++<<":\n";
		while (m--)
		{
			cin>>q;
			auto p=upper_bound(sumas, sumas+k, q);
			int l=p- sumas;
			//cout<<l<<endl;
			//cout<<*p<<endl;
			if (l==k) res=sumas[k-1];
			else if (l==0) res=sumas[0];
			else if ( abs( sumas[l-1]-q )<abs(sumas[l]-q) )
				res= sumas[l-1];
			else res=sumas[l];
			cout<<"Closest sum to "<<q<<" is "<<res<<".\n";
		}
	}
	return 0;
}
