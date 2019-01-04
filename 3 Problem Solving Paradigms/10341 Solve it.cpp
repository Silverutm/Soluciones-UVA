#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1E-9
using namespace std;
int p, q, r, s, t ,u;
double f(double x)
{
	return p*exp(-x) + q*sin(x) +r*cos(x) + s*tan(x) + t*x*x +u;
}

double fp(double x)
{
	return -p*exp(-x) + q*cos(x) -r*sin(x) + s/(cos(x)*cos(x)) + 2*t*x;	
}

int main()
{
	double x1, x2, x3;
	int i;
	while ( scanf("%d %d %d %d %d %d",&p, &q, &r, &s, &t, &u )==6 )
	{
		if (f(0.0)==0 ) printf("%.4lf\n", 0.0);
		else if (f(1.0)==0 ) printf("%.4lf\n", 1.0);
		else if ( f(0.0)*f(1.0)<0.0 )
		{
			//xant=0.0;
			x1=0.0; x2=1.0;
			for (i=0; i<300 and fabs(f(x2)-f(x1))>eps ; ++i)
			{
				//xant=xant -f(xant)/fp(xant);
				x3=x2-(x2-x1)*f(x2)/(f(x2)-f(x1));
				x1=x2; x2=x3;
			}

			//printf("%lf\n", fp(0.0));
			printf("%.4lf\n", x3);
		}
		else printf("No solution\n");
	}

	return 0;
}