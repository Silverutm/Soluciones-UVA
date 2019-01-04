#include <bits/stdc++.h>
#define s second
#define f first
#define mk make_pair
#define pb push_back
#define tam 305
#define INF 10000000000000LL
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int t, n, m, comprados[tam], indice, cj, i ,j;
ll dia_articulo[tam][tam];
ll total, parcial;

int main()
{
	cin>>t;
	for (int caso = 1; caso <= t; ++caso)
	{
		memset(comprados, 0, sizeof comprados);		
		total = 0LL;

		cin>>n>>m;
		for ( i = 0; i < n; ++i)		
			for ( j = 0; j < m; ++j)
				cin>>dia_articulo[i][j];

		for ( i = 0; i < n; ++i)
			sort( dia_articulo[i], dia_articulo[i] + m);

		
		for ( i = 0; i < n; ++i)
		{
			parcial = INF;
			indice = 0;
			for ( j = 0; j <= i; ++j)
			{
				cj = comprados[j];
				if ( cj < m )
					if ( parcial > 2*(cj+1)-1 + dia_articulo[j][cj] )
					{
						parcial = 2*(cj+1)-1 + dia_articulo[j][cj];
						indice = j;
					}
					//parcial = min(parcial, 2*(cj+1)-1 + dia_articulo[j][cj] )
			}
			++comprados[indice];
			total += parcial;
		}

		cout<<"Case #"<< caso <<": "<< total <<"\n";
	}
	return 0;
}