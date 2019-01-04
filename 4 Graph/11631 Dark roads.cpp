#include <bits/stdc++.h>
#define tam 200007
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair <ll, int> ii;
vector <pair <int, ll>> Lista[tam];
bitset<tam> visitado;
priority_queue<ii, vector <ii>, greater<ii>> cola_pr;
ll peso_arbol, peso_grafica;
int n;

void procesar(int v)
{
	int u; ll w;
	visitado[v] = true;
	for (auto &e:Lista[v])
	{
		u = e.first; w = e.second;
		if (not visitado[u])
			cola_pr.push( ii{w, u} );
	}
}

void prim()
{
	int u; ll w;
	while (not cola_pr.empty())
	{
		auto e = cola_pr.top(); cola_pr.pop();
		u = e.second; w = e.first;
		if (visitado[u]) continue;

		peso_grafica += w;
		procesar(u);
	}
	
}

int main()
{
	int m, a, b;
	ll w;
	while (cin>>n>>m and n)
	{
		peso_arbol = peso_grafica = 0LL;
		visitado.reset();		
		for (int i = 0; i < n; ++i)
			Lista[i].clear();

		while (m--)
		{
			cin>>a>>b>>w;
			Lista[a].push_back( mk(b, w) );
			Lista[b].push_back( mk(a, w) );

			peso_arbol += w;
		}

		//for (int i = 0; i < n; ++i)
		//{
			//while (not cola_pr.empty() ) cola_pr.pop();
			procesar(0);
			prim();
		//}

		cout<<peso_arbol- peso_grafica<<"\n";
		//cout<<peso_grafica<<"\n";
		//cout<<peso_arbol<<"\n";
	}
	return 0;
}