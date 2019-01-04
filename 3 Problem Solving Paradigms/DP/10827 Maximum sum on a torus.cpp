#include <iostream>
#include <algorithm>
using namespace std;
#define N 320
int entrada[N][N], suma[N][N];

int main()
{
	int n, t, i, j, k, l, tam, mayor, a;
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (i=1; i<=n; ++i)
			for (j=1; j<=n; ++j)
			{
				cin>>a;
				entrada[i][j]= entrada[i+n][j]=
					entrada[i][j+n]= entrada[i+n][j+n]=a;
			}
		tam=2*n;
		for (i=1; i<=tam; ++i)
			for (j=1; j<=tam; ++j)
				suma[i][j]=entrada[i][j] + suma[i-1][j] 
						+ suma[i][j-1] - suma[i-1][j-1];

		mayor=suma[1][1];
		for (i=1; i<=tam; ++i)
			for (j=1; j<=tam; ++j)
				for (k=i; k<=min(tam, i+n-1); ++k)
					for (l=j; l<=min(tam, j+n-1); ++l)
						mayor = max( mayor, suma[k][l] - 
							suma[i-1][l] - suma[k][j-1] + suma[i-1][j-1] );
		cout<<mayor<<endl;
	}
	return 0;
}
