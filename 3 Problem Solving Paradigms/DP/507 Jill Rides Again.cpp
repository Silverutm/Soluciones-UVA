#include <iostream>
#include <algorithm>
using namespace std;
#define tam 20005
int lista[tam], resultado[tam], inicio[tam];
int r, t, n, sum, ini, ind_max, i;

int maximo()
{
	ind_max=1 ;
	for ( i=2; i<=n; ++i)
	{
		if ( resultado[i]>resultado[ind_max] )
			ind_max=i;
		else if (resultado[i]==resultado[ind_max]  )
		{
			if  ( i- inicio[i] > ind_max - inicio[ind_max] )
				ind_max=i;
			else if ( i- inicio[i] == ind_max - inicio[ind_max] )
			{
				if (inicio[i] < inicio[ind_max]) ind_max=i;
			}
		}
	}
}

int main()
{
	cin>>t;
	for (r=1; r<=t; ++r)
	{
		cin>>n;
		resultado[1]=lista[1]=0;
		inicio[1]=1;
		for ( i=2; i<=n; ++i)
			cin>>lista[i];

		for ( i=2; i<=n; ++i)
		{
			sum=lista[i]+resultado[i-1];
			if (sum<0) ini=i;
			else ini=inicio[i-1];

			inicio[i]=ini;
			resultado[i] = max(sum, 0);
		}
		maximo();
		if (ind_max>1)
		cout<<"The nicest part of route "<<r<<" is between stops "
			<<inicio[ind_max]<<" and "<<ind_max<<endl;
		else cout<<"Route "<<r<<" has no nice parts\n";
	}
	return 0;
}