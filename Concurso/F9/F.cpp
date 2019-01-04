#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define tam 2502
//typedef long double ld;
double A[tam], B[tam], C[tam], faclog[tam];
//int arra[tam], arrb[tam], arrc[tam];
double EPS = 1e-7;
int main()
{
	faclog[0] = faclog[1] = 0.0;  faclog[2] = 1.0;
	for (int i = 3; i < tam; ++i)
		faclog[i] = faclog[i-1] + log2( double(i) );
	//cout<<faclog[2500]<<endl;
	//printf("%lf\n",faclog[2500] );
	int n, na, nb, nc, x ;
	double ta, tb, tc;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d %d %d", &na, &nb, &nc);
		ta = tb = tc = 0.0;
		while (na--)
		{
			scanf("%d", &x);
			ta += faclog[x];
		}

		while (nb--)
		{
			scanf("%d", &x);
			tb += faclog[x];
		}

		while (nc--)
		{
			scanf("%d", &x);
			tc += faclog[x];
		}
		printf("Case #%d: ", i);
		if (ta > tb and fabs(ta - tb)>EPS and ta > tc and fabs(ta - tc)>EPS )
			printf("A\n");
		else if (tb > ta and fabs(tb - ta)>EPS and tb > tc and fabs(tb - tc)>EPS )
			printf("B\n");
		else if (tc > tb and fabs(tc - tb)>EPS and tc > ta and fabs(tc - ta)>EPS)
			printf("C\n");
		else printf("TIE\n");
		
	}
	
	return 0;
}