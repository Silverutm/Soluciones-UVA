#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int k, y, x, n, i, yy[20009], xx[20009];
	while ( scanf("%d", &k)==1 )
	{
		y=k+1; n=0;
		while ( y<=2*k )
		{
			if ( ( (k*y)%(y-k)  )==0 ) 
			{
				x=k*y/(y-k);
				xx[n]=x; yy[n]=y;
				++n;
			}
			++y;
		}
		printf("%d\n",n );
		for (i=0; i<n; ++i)
			printf("1/%d = 1/%d + 1/%d\n",k, xx[i], yy[i] );
	}
	return 0;
}