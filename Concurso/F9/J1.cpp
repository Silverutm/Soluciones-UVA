#include <bits/stdc++.h>
using namespace std;
#define INF -100000000000LL
vector <int> v;
int legal(int cant, int indice)
{
	if (indice == 1) return cant;
	return min(cant, indice/2);
}
long long tabla[505][505];
long long f( int cant, int indice )
{
	if (cant < 0) return INF;
	if (tabla[cant][indice]!=-1) return tabla[cant][indice];
	if ( cant == 0 ) return tabla[cant][indice]=0;

	if (indice == 0) return tabla[cant][indice]=0;

	//if ( indice!=1 and cant < indice/2) f (   cant, indice-1 );
	/*else*/ return tabla[cant][indice]=max (  
		f (   legal(cant-1, indice-1)  , indice-1 ) + v[indice-1], 	
		f (   legal(cant, indice-1) , indice-1 )	
		 );
}

int main()
{
	int n, m, a;
	long long res;
	cin>>n;
	
	for (int caso = 1; caso <= n; ++caso)
	{
		cin>>m;
		v.clear();
		memset(tabla, -1, sizeof tabla);
		
		while (m--)
		{
			cin>>a;
			v.push_back(a);
		}
		
		res= f( max((int)v.size()/2, 1) , v.size() );

		printf("Spree #%d: %lld\n", caso, res);
	}
	return 0;
}