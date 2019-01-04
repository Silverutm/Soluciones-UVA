#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int t, p, i, n, arreglo[30], suma, j;
	bool posible;
	cin>>t;
	while (t--)
	{
		cin>>n>>p;
		for (i=0; i<p; ++i)
			cin>>arreglo[i];
		posible=true;
		for (i=0; i< (1<<p) and posible ; ++i)
		{
			suma=0;
			for (j=0; j<p; ++j)
			{
				if (i & (1<<j) )
					suma+=arreglo[j];
			}
			if (suma==n)
			{
				printf("YES\n");
				posible=false;
			}
		}
		if (posible) printf("NO\n");
	}
	return 0;
}