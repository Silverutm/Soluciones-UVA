#include <cstdio>
using namespace std;
int main()
{
	int n, b, h, w, p,  i, habimax, preciomin, preciotemp, cant, j;
	while ( scanf("%d %d %d %d", &n, &b, &h, &w)==4 )
	{
		preciomin=10000000;
		for (i=0; i<h; ++i)
		{
			scanf("%d", &p);
			scanf("%d", &habimax);
			for (j=1; j<w; ++j)
			{
				scanf("%d", &cant);
				if (cant>habimax)
					habimax=cant;
			}
			if (habimax>=n)
			{
				preciotemp=n*p;
				if (preciotemp<preciomin && preciotemp<=b)
					preciomin=preciotemp;
			}
		}
		if (preciomin!=10000000)
			printf("%d\n",preciomin );
		else printf("stay home\n");
	}
	return 0;
}