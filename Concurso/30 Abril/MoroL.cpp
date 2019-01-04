#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <bitset>
#include <queue>
#include <map>
#define tam 100006
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair < int, int > ii;
struct Arista { int u, l; };

int n;
bitset <tam> visitado;
int paps[tam], niveles[tam];
ll distancia[tam];
queue <int > cola;
map < ii, int > mapa;
vector < vector <Arista> > Lista;

void busqueda()
{
	int v, u, d, i;
	cola.push(1);
	while ( !cola.empty() )
	{
		v= cola.front(); cola.pop();
		for (i=0; i<Lista[v].size(); ++i)
		{
			u=Lista[v][i].u; d=Lista[v][i].l;
			if (visitado[u]) continue;
			visitado[u]=true;
			cola.push( u );
			distancia[u]=distancia[v]+d;
			paps[u]=v; niveles[u] = niveles[v]+1;
		}
	}
}


int main()
{
	int i, p, a, b, l ,h, r,  s, ar, as, maxi, temp, dif;
	ll res;
	paps[1]=-1; distancia[1]=0; niveles[1]=0;
	while ( scanf("%d", &n)!=EOF )
	{
		Lista.clear();
		Lista.resize( n+1 );
		visitado.reset();
		visitado[1]=true;
		mapa.clear();
		for (i=1; i<n; ++i)
		{
			scanf("%d %d %d %d", &a, &b, &h, &l);
			Lista[a].pb( Arista{b,l} );
			Lista[b].pb( Arista{a,l} );
			mapa[ii(a,b)]=h;
			mapa[ii(b,a)]=h;
		}
		busqueda();

		/*for (i=1; i<=n; ++i)
			cout<<i<<" ";
		cout<<endl;
		for (i=1; i<=n; ++i)
			cout<<distancia[i]<<" ";
		cout<<endl;
		for (i=1; i<=n; ++i)
			cout<<paps[i]<<" ";
		cout <<endl;
		*/
		scanf("%d", &p);
		while (p--)
		{
			scanf("%d %d", &r, &s);
			dif= min( niveles[r],niveles[s] );

			ar=r; as=s; maxi=0;
			while (niveles[ar]!=dif)
			{
				temp=paps[ar];
				maxi=max( mapa[ii(ar,temp)], maxi );
				ar=temp;
			}
			while (niveles[as]!=dif)
			{
				temp=paps[as];
				maxi=max( mapa[ii(as,temp)], maxi );
				as=temp;
			}

			while (as!=ar)
			{				
				temp=paps[ar];
				maxi=max( mapa[ii(ar,temp)], maxi );
				ar=temp;

				temp=paps[as];
				maxi=max( mapa[ii(as,temp)], maxi );
				as=temp;
			}
			res=distancia[r]-distancia[ar]+distancia[s]-distancia[ar];
			printf("%lld\n", res*maxi);
			//cout<<res*maxi<<endl;
		}
	}
	return 0;
}