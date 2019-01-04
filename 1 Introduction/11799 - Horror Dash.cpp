#include<cstdio>
using namespace std;
int main()
{
	int t, n, max, i, numero, j;
	scanf("%d", &t);
	for (j=1; j<=t; ++j)
	{
		scanf("%d", &n);
		scanf("%d", &max);
		for (i=1; i<n; ++i)
		{
			scanf("%d", &numero);
			if (numero>max)
				max=numero;
		}
		printf("Case %d: %d\n",j, max );
	}
	return 0;
}