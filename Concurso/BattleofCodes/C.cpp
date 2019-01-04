#include <iostream>
using namespace std;
int matriz[200][200];

void pinta(int iini, int ifin, int jini, int jfin, int valor)
{
	for ( ;iini<=ifin; ++iini)
		for (int j=jini;j<=jfin; ++j)
			matriz[iini][j]=valor;
}

int main()
{
	int i, j, n, mitad;
	cin>>n;
	mitad=(n+1)/2;
	for (i=1; i<=mitad; ++i)
	{
		pinta( i,i,i, n-i+1, i);
		pinta( n-i+1,n-i+1,i, n-i+1,  i);

		pinta(   i, n-i+1,i,i , i);
		pinta(   i, n-i+1, n-i+1,  n-i+1, i);
	}
	for (i=1; i<=n; ++i)
	{
		for (j=1; j<=n; ++j)	
			cout<<matriz[i][j];
		cout<<endl;
	}
	return 0;
}