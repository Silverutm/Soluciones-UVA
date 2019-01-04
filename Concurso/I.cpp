#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int t, matriz [5][105], n, i, v, f, j;
	bool b;
	char l;	
	scanf("%d", &t);
	while(t--)
	{
		memset(matriz, 0, sizeof matriz);
		b=false;
		scanf("%d", &n);
		for (i=0; i<n; ++i)
		{	
			scanf("%d%c", &v, &l);
			if (l=='r') f=1;
			else if (l=='g') f=2;
			else if (l=='b') f=3;
			matriz[f][v]=1;
		}
		for (i=1; i<=3; ++i)
			for (j=1; j<=98; ++j)
				if ((matriz[i][j]+matriz[i][j+1]+matriz[i][j+2])==3)
				{
					b=true;
					j=100;
					i=4;
				}

		if (b==false)
			for (j=1; j<=100; ++j)
				if ((matriz[1][j]+matriz[2][j]+matriz[3][j])==3)
				{
					b=true;
					j=100;
				}
		if (b) printf("YES\n");
		else printf("NO\n");

	}
	return 0;
}