#include <iostream>
using namespace std;
int n, m;
char matN[1000][1000], matM[1000][1000], Com[1000][1000];

void girar()
{
	int i,j;
	for (i=1; i<=m; ++i)
		for (j=1; j<=m; ++j)
			Com[j][m-i+1]=matM[i][j];

	for (i=1; i<=m; ++i)
		for (j=1; j<=m; ++j)
			matM[i][j]=Com[i][j];
	return ;
}		

int res()
{
	int r=0, i, j, k,l, posible;
	for (i=1; i<=n-m+1; ++i)
		for (j=1; j<=n-m+1; ++j)
		{
			posible=1;
			for (k=1; k<=m and posible; ++k)
				for (l=1; l<=m and posible; ++l)
					if (matM[k][l]!= matN[i+k-1][j+l-1])
						posible=0;
			r += posible;
		}	

	girar();
	return r;
}

int main()
{
	int i, j;
	while (cin>>n>>m and n)
	{
		for (i=1; i<=n; ++i)
			for (j=1; j<=n; ++j)
				cin>>matN[i][j];
		for (i=1; i<=m; ++i)
			for (j=1; j<=m; ++j)
				cin>>matM[i][j];
		cout<<res()<<" ";
		cout<<res()<<" ";
		cout<<res()<<" ";
		cout<<res()<<endl;
	}
	return 0;
}