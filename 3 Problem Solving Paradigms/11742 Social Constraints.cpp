#include <iostream>
#include <algorithm>
#include <cstdlib>
#define fi first
#define se second

using namespace std;
typedef pair<int, int> ii;

int arreglo[10], n, m;
pair <ii, int> restricciones[30];

int fin(int a)
{
	for (int i=0; i<n; ++i)
		if (arreglo[i]==a)
			return i;
}

int main()
{
	int a, b, c, i, j, x, y, contador;
	bool posible;
	while (cin>>n>>m and( n or m) )
	{
		for (i=0; i<n; ++i)
			arreglo[i]=i;
		for (i=0; i<m; ++i)
		{
			cin>>a>>b>>c;
			restricciones[i].fi.fi=a;
			restricciones[i].fi.se=b;
			restricciones[i].se=c;
		}
		contador=0;
		do
		{
			posible=true;
			for (i=0; i<m; ++i)
			{
				x=fin(restricciones[i].fi.fi);
				y=fin(restricciones[i].fi.se);
				c=restricciones[i].se;
				if (c<0)
				{
					if ( abs(x-y)< abs(c) )
						posible=false;
				}
				else if ( abs(x-y)> abs(c) )
						posible=false;
			}
			contador +=posible;	
		}while ( next_permutation( arreglo, arreglo+n ) );
		cout<<contador<<endl;
	}
	return 0;
}