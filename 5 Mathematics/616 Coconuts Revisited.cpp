#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	int n, raiz, res, k, f, j;
	while (scanf("%d", &n) and n>=0)
	{
		--n;
		raiz = sqrt(n);
		res = -1;
		for (int i = raiz+1; i > 1; --i)
		{
			if ( n%i==0 )
			{
				k = i;
				f =n+1;
				for ( j = 0; j < k; ++j)
				{
					if (f%k!=1) break;
					f = f-1-(f-1)/k;
				}
				if (j==k and f%k==0)
				{
					res = k;
					break;
				}
			}
		}
		printf("%d coconuts, ", n+1);
		if (res!=-1)
			printf("%d people and 1 monkey\n", k);
		else
			printf("no solution\n");
	}
	return 0;
}
