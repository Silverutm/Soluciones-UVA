#include <iostream>
//#include <vector>
#include <algorithm>
using namespace std;
int  lista[10009], sumas[10009];
int main()
{
	int n, maximo, i;
	while (cin>>n, n)
	{
		for (i=1; i<=n; ++i)
			cin>>lista[i];
		maximo=-1;
		for (i=1; i<=n; ++i)
		{
			sumas[i]=max( sumas[i-1]+lista[i], 0);
			maximo=max(sumas[i], maximo);
		}
		if (maximo<=0) cout<<"Losing streak.\n";
		else cout<<"The maximum winning streak is "<<maximo<<".\n";
	}
	return 0;
}
