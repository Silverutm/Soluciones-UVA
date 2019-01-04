#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
long long x, y, z, a, b, c, mini, raiz, bx;

int main()
{
	int t;
	cin>>t;
	double r=1;
	bool sol;
	while (t--)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		sol=false;
		double temp1=sqrt(c), tem2=pow(b, r/3);
		mini= temp1 < tem2 ? temp1:tem2;
		//cout<<"faf\n";
		/*for (x=-mini; x<=mini and !sol; ++x)
		{
			if (!x) continue;
			if (b%x) continue;
			bx=b/x;
			raiz=sqrt(bx);
			for (y=x+1; y<=raiz and !sol; ++y)
			{
				if (!y) continue;
				if (bx%y) continue;
				z= bx/y;
				if (z!=x and z!=y)
					if (x+y+z==a and x*x+y*y+z*z==c)
					{
						sol=true;
						printf("%lld %lld %lld\n",x,y,z );
					}
			}
		}*/

		for (x=-mini; x<0 and !sol; ++x)
		{			
			if (b%x) continue;
			bx=-b/x;
			raiz=sqrt(bx);
			y= -(x+1)<raiz ? x+1:raiz; 
			for (; y<0 and !sol; ++y)
			{				
				if (bx%y) continue;
				z= -bx/y;
				if (z!=x and z!=y)
					if (x+y+z==a and x*x+y*y+z*z==c)
					{
						sol=true;
						printf("%lld %lld %lld\n",x,y,z );
					}
			}
		}

		for (x=1; x<=mini and !sol; ++x)
		{						
			if (b%x) continue;
			bx=b/x;
			raiz=sqrt(bx);
			long long men= x+1<raiz ? x+1:raiz; 
			for (y=1; y<=men and !sol; ++y)
			{				
				if (bx%y) continue;
				z= bx/y;
				if (z!=x and z!=y)
					if (x+y+z==a and x*x+y*y+z*z==c)
					{
						sol=true;
						printf("%lld %lld %lld\n",x,y,z );
					}
			}
		}
		if (!sol) printf("No solution\n");

	}
	return 0;
}