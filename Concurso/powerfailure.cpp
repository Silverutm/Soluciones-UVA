#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char matriz[105][105];
int contador, plantas;

void llenar(int i, int j)
{
	if (matriz[j][i]==1)
	{
		//printf("%d %d\n", i, j);
		++plantas;
		matriz[j][i]=2;
		if (j>0)
		llenar(i,j-1);
		llenar(i,j+1);
		if (i>0)
		llenar(i-1,j);
		llenar(i+1,j);
	}
}

void imprimir(int m, int n)
{
int i, j;
for (i=0; i<m; ++i, printf("\n" ))
for (j=0; j<n; ++j)
	printf("%d ",matriz[i][j] );

}

int main()
{
	int t, n, i, j, x, y, c, p, m;
	char l;
	scanf("%d", &t);
	while(t--)
	{
		memset(matriz, 0, sizeof matriz);
		scanf("%d %d %d %d", &n, &m, &p, &c);
		plantas=contador=0;
		for (i=0; i<=n; ++i)
			matriz[m][i]=0;

		for (i=0; i<=m; ++i)
			matriz[i][n]=0;

		while (p--)
		{
			scanf("%d %d", &x, &y);
			if (matriz[y][x]==0)
				++plantas;
			matriz[y][x]=2;			
		}
		while (c--)
		{
			scanf("%d %d %c", &x, &y, &l);
			if (matriz[y][x]==0)
			matriz[y][x]=1;
			if (l=='R')  {if (matriz[y][x+1]==0) matriz[y][x+1]=1;}
			else if (matriz[y+1][x]==0) matriz[y+1][x]=1;
		}
		bool b;
		printf("plantas %d\n", plantas);
		

		//imprimir(m, n);
		//printf("%c\n",10 );
		//printf("%c\n",10 );
		//printf("%c\n",10 );
//continue;
		for (i=0;i<n; ++i)
			for (j=0;j<m; ++j)
				if (matriz[j][i]==2)
				{
					b=true;
					if (j>0)
					llenar(i,j-1);
					llenar(i,j+1);
					if (i>0)
					llenar(i-1,j);
					llenar(i+1,j);
				}
		printf("plantas %d\n", plantas);
		printf("%d\n", n*m-plantas);
	}
	return 0;
}