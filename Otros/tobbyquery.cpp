#include <iostream>
#include <cstring>
using namespace std;
int arreglo[11][100009];
int main()
{
	int n, m, k, l, r, i, a, j;
	while (cin>>n)
	{
		memset(arreglo, 0, sizeof arreglo);
		for (i=1; i<=n; ++i)
		{
			cin>>a;
			for (j=0; j<=9; ++j)
				arreglo[j][i] = arreglo[j][i-1];
			arreglo[a][i]++;
		}
		cin>>k;
		while (k--)
		{			
			cin>>l>>m;
			r=0;
			for (i=0; i<=9; ++i)
				r+= (arreglo[i][l-1]!=arreglo[i][m]);
			cout<<r<<endl;
		}
	}
	return 0;

}