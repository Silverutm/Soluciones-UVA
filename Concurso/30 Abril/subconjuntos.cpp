#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int arreglo[30];
int main()
{
	int n, k, i, a, b;
	cin>>n>>k>>a>>b;
	--a; --b; --b;
	for (i=0; i<n-k; ++i)
		arreglo[i]=0;
	for (; i<n; ++i)
		arreglo[i]=1;
	for (i=0; i<n; ++i)
		printf("%3d", i+1);
	printf("\n\n");
	int p, tot=0;
	do
	{
		p=0;
		for (i=0; i<n; ++i)
		{	
			printf("%3d", arreglo[i]);
			if (i>=a and i<=b and arreglo[i])
				p=1;
		}
		tot+=p;
		printf("\n");
	}while ( next_permutation(arreglo, arreglo+n) );

	printf("\n");
	for (i=0; i<n; ++i)
		printf("%3d", i+1);
	printf("\n\n%d\n", tot);

	return 0;
}