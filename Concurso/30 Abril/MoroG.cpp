#include <iostream>
#include <bitset>
#include <queue>
#include <vector>
#include <cstring>
#define tam 105
#define se second
#define fi first
using namespace std;
typedef pair <int, int > ii;
typedef vector < ii > vii;
typedef long long ll;

priority_queue< ii, vector<ii>, greater<ii> > pq;
//queue < ii > pq;
vector < vii > Lista;
int vecinos[tam][tam], paps[tam], peps[tam];
bitset <tam> visitados;
ll  distancias[tam];
int V, E;
void dikstra()
{
	//memset(distancias, 99999999, sizeof distancias);
	for (int i=1; i<=V; ++i)
		distancias[i]=99999999999LL;
	memset(paps, -1, sizeof paps);
	visitados.reset();

	distancias[1]=0; ii frente; int v, dv, u, wu;
	pq.push( ii(distancias[1] ,1) );
	while ( !pq.empty() )	
	{
		frente=pq.pop(); pq.pop();
		v=frente.se; dv=frente.fi;
		if (visitados[ v ] ) continue;
		visitados[ v ]=true;

		for (int i=0; i<Lista[v].size(); ++i)
		{			
			u=Lista[v][i].fi; wu=Lista[v][i].se; 
					
			if ( distancias[u] > distancias[v] + wu )
			{
				distancias[u] = distancias[v] + wu	;
				paps[u]=v;
				pq.push( ii(distancias[u], u) );
			}
		}
	}
	return;
}


void dikstra22()
{
	//memset(distancias, 99999999, sizeof distancias);
	for (int i=1; i<=V; ++i)
		distancias[i]=99999999999LL;
	visitados.reset();

	distancias[1]=0; ii frente; int v, dv, u, wu;
	pq.push( ii(distancias[1] ,1) );
	while ( !pq.empty() )	
	{
		frente=pq.pop(); pq.pop();
		v=frente.se; dv=frente.fi;
		//if (visitados[ v ] ) continue;
		visitados[ v ]=true;

		for (int i=0; i<Lista[v].size(); ++i)
		{			
			u=Lista[v][i].fi; wu=Lista[v][i].se; 
			
			if (peps[u]==v) continue; //ya lo intente antes
			if (peps[v]==u) wu=-wu;

			//if ( vecinos[u][v] ) wu=-wu;
			//if ( !vecinos[v][u] ) continue;
			//if ( visitados[u] ) continue;
			if ( distancias[u] > distancias[v] + wu )
			{
				distancias[u] = distancias[v] + wu	;
				pq.push( ii(distancias[u], u) );
			}
		}
	}
	return;
}






int main()
{
	int a, b, w;

	ll res;
	while (cin>>V>>E)
	{
		memset(vecinos, 0, sizeof vecinos);
		Lista.clear();
		Lista.resize(V+1);
		while (E--)
		{
			cin>>a>>b>>w;
			Lista[a].push_back( ii(b,w) );
			Lista[b].push_back( ii(a,w) );
			vecinos[a][b]=vecinos[b][a]=1;
		}
		//rifate un dikstra paps
		dikstra();
		res=distancias[V];
		//cout<<distancias[V]<<endl;
		int u=V, x;
		while (u!=-1)
		{
			peps[u]=paps[u];
			x=paps[u];
			
			//if (x!=-1)
			//	vecinos[x][u]=0;
				//vecinos[u][x]=vecinos[x][u]=0;

			u=x;	
		}
		//borrar aristas y correr dikstra
		dikstra22();
		res += distancias[V];
		//cout<<distancias[V]<<endl<<endl;
		cout<<res<<endl;
	}
	return 0;
}