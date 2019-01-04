#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, i, j, k, p, c;
	while (cin>>n)
	{
		if (n<0) continue;
		p=c=0;
		for (i=0; i<61; ++i)
			for (j=0; j<61; ++j)
				for (k=0; k<61; ++k)
					if (i+j+k==n)
					{
						++p;
						if (i<=j and j<=k)
							++c;
					}
		if (c)
		{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",n,c );
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, p);				
		}
		else
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}