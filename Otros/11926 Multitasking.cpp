#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define mk make_pair
using namespace std;
typedef pair <int, int> ii;
typedef vector < ii > vii;

bool f(ii a, ii b)
{ return a.second < b.second; }

int main()
{
	int i, m, n, a, b, t, z, j;
	vii v;
	bool posible;
	while ( scanf("%d %d", &n, &m)==2 and (n or m) )
	{
		v.clear();
		//Recibir intervalos
		for (i=0; i<n; ++i)
		{
			cin>>a>>b;
			v.pb(mk(a,b));
		}

		//Recibir intervalos repetitivos
		for (i=0; i<m; ++i)
		{
			cin>>a>>b>>t;
			z=0;
			do //crear las repeticiones
			{
				v.pb( mk(a+z, b+z ) );
				z +=t;
			}
			while ( z+a<=1000000 );
		}

		//ordenar por hora en que finalizan
		sort(v.begin(), v.end(), f);
		j=0;
		posible=true;

		for (i=1; i<v.size() and posible;++i )
		{
			//si se traslapan entonces hay conflicto
			if ( v[i].first < v[j].second ) 
				posible=false;
			j=i;
		}
		if (posible) printf("NO CONFLICT\n" );
		else printf("CONFLICT\n" );
	}
	return 0;
}