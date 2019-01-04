#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define tam 105
int tabla[tam][tam], suma[tam][tam];

int main()
{
	int n, i, j, k ,l , maximo;
	cin>>n;
	for (i=1; i<=n; ++i)
		for (j=1; j<=n; ++j)
			cin>>tabla[i][j];

	for (i=1; i<=n; ++i)
		for (j=1; j<=n; ++j)
			suma[i][j] = tabla[i][j] + suma[i][j-1] 
						+ suma[i-1][j] - suma[i-1][j-1];
	maximo=suma[1][1];
	for (i=1; i<=n; ++i)
		for (j=1; j<=n; ++j)
			for (l=i; l<=n; ++l)
				for (k=j; k<=n; ++k)
					maximo=max(maximo, 
						suma[l][k] + suma[i-1][j-1] -suma[l][j-1] - suma[i-1][k] );
	cout<<maximo<<endl;

	//for (i=0; i<=n; ++i, cout<<endl)
	//	for (j=0; j<=n; ++j)
	//		cout<<suma[i][j]<<" ";
	return 0;
}