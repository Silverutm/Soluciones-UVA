#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char matriz[105][105];
int contador;
void llenar(int i, int j)
{
	if (matriz[i][j]=='-')
	{
		matriz[i][j]='w';
		++contador;
		llenar(i+1,j);
		llenar(i-1,j);
		llenar(i,j+1);
		llenar(i,j-1);
		llenar(i+1,j+1);
		llenar(i+1,j-1);
		llenar(i-1,j+1);
		llenar(i-1,j-1);
	}
	return;
}

int main()
{
	int t, n, i, j;
	scanf("%d", &t);
	while(t--)
	{
		memset(matriz, 0, sizeof matriz);
		contador=0;
		scanf("%d", &n);
		for (i=0; i<n; ++i)
			cin>>matriz[i];

		//for (i=0; i<n; ++i, cout<<endl)
		//	for (j=0; j<n; ++j)
		//	cout<<matriz[i][j];
		//continue;
		for (i=0; i<=n; ++i)
			matriz[n][i]=matriz[i][n]='b';

		for (i=0; i<n; ++i)
			for (j=0; j<n; ++j)
				if (matriz[i][j]=='w')
				{					
					llenar(i+1,j);
					llenar(i-1,j);
					llenar(i,j+1);
					llenar(i,j-1);
					llenar(i+1,j+1);
					llenar(i+1,j-1);
					llenar(i-1,j+1);
					llenar(i-1,j-1);
				}
		printf("%d\n",contador );
	}
	return 0;
}