#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char matriz[5005][5005];
int t, n, m, res, f;
int jj[]={-1, 0, 1, 1, 1, 0, -1, -1}, ii[]={-1, -1, -1, 0,1, 1, 1, 0};
void resolver(int i, int j)
{
	int k;
	for (k=0; k<8; ++k)
	if ((i+ ii[k])>=0 && (j+jj[k] )>=0  && (i+ ii[k])<n && (j+jj[k] )<n)
		if (matriz[ i+ii[k] ][ j+jj[k] ]=='P' || matriz[i+ii[k]][j+jj[k]]=='p')
			{
				++res;
				matriz[ i+ii[k] ][ j+jj[k] ]='K';
				resolver( i+ii[k] , j+jj[k] );
			}
	
}

int main()
{
	freopen("data.out", "w", stdout);
	freopen("data.in", "r", stdin);

	int i, j;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &f);
		res=0;
		memset(matriz, 0, sizeof matriz);
		for (i=0; i<n; ++i)
			cin>>matriz[i];
		for (i=0; i<n; ++i)
			for (j=0; j<n; ++j)
				if (matriz[i][j]=='V' || matriz[i][j]=='v')
				{	 
					 ++res;
					 resolver(i, j);
				}

		if (res>=f ) printf("Contagiados de por vida\n");
		else printf("Virus eliminado\n");
		for (i=0; i<n; ++i)
			cout<<matriz[i]<<endl;


	}
}