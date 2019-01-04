#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int arreglo[10007], matriz[105][105];
vector <int > respuesta;

void general()
{
	int k, z, i;
	for (i=2; i<=10005; ++i)
	{
		k=2;
		while ((z=i*k)<=1005)
		{
			arreglo[z]=1;
			++k;
		}
	}
	for (i=1; i<=10005; ++i)
		if (arreglo[i]==0) respuesta.push_back(i);
}

int main()
{
	freopen("data.out", "w", stdout);
	freopen("data.in", "r", stdin);
	int t, j, i, mul, k, irespuesta, col, ren, indice;
	scanf("%d", &t);
	general();
	//for (auto pu:respuesta)
	//	cout<<" "<<pu;
	//return 0;
	for (j=1; j<=t; ++j)
	{
		scanf("%d %d", &col, &ren);
		memset(matriz, -1, sizeof matriz);
		printf("Caso %d :", j);
		i=-1;
		mul=col*ren;
		while (++i<respuesta.size() && respuesta[i]<=mul)			
			{
				if (i==0) printf("%d", respuesta[i]);
				else printf(" %d", respuesta[i]);
			}
		printf("\n");


		indice=0, irespuesta=0;
		for (k=1; k<=col; ++k)
			for (i=1; i<=ren; ++i)
			{
				++indice;
				if (indice==respuesta[irespuesta] ) {matriz[i][k]=indice; ++irespuesta;}
				else matriz[i][k]=-1;
			}

		for (i=1; i<=ren; ++i, printf("\n"))
			for (k=1; k<=col; ++k)
			{
				if (k==1)
				{
					if (matriz[i][k]!=-1) printf("%4d", matriz[i][k]);
					else printf("%4c",'*' );	
				}
				else 
				{
				if (k>1) printf(" ");
				if (matriz[i][k]!=-1) printf("%4d", matriz[i][k]);
				else printf("%4c",'*' );
				}
			}
		
	}
	return 0;
}