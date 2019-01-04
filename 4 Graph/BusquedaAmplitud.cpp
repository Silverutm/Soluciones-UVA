#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define pb push_back
#define mk make_pair
using namespace std;
typedef pair <int, int> ii;
typedef vector < ii > vii;

vector < vii > ListaAdj;
queue <int > cola;
int distancias[1000], papas[1000];

void buscar()
{
	int u,v;
	while (!cola.empty())
	{
		u=cola.front();
		cola.pop();
		for (int i=0; i<ListaAdj[u].size(); ++i)
		{
			v= ListaAdj[u][i].first;
			if (distancias[v]==-1)
			{
				papas[v]=u;
				distancias[v] =distancias[u]+1;
				cola.push(v);
			}
		}
	}
	return;
}

int main()
{
	int n, m,a ,b;
	cin>>n>>m;
	char aasd[]="123";
	string ff="123";
	if (aasd==ff) cout<<"asdfdasf"<<endl;
	return 0;
	ListaAdj.resize(n+1);
	while (m--)
	{
		cin>>a>>b;
		ListaAdj[a].pb( mk(b, 1) );
		ListaAdj[b].pb( mk(a, 1) );
	}
	memset(papas, -1, sizeof papas);
	memset(distancias, -1, sizeof distancias);
	distancias[1]=0;
	cola.push( 1 );
	buscar();
	for (int i=1; i<=n; ++i)
		cout<<i<<" ";
	cout<<endl;
	for (int i=1; i<=n; ++i)
		cout<<distancias[i]<<" ";
	cout<<endl;
	int v=6;
	
	
	while ( v!=-1 )
	{		
		cout<<v<<" ";
		v=papas[v];
	}
	cout<<endl;
	return 0;
}