#include <bits/stdc++.h>
#define mk  make_pair
#define tam 1005
using namespace std;

typedef long long ll;
vector < pair< ll, pair<int, int> > > ListaAristas;
vector <ll> omitidos;
int papa[tam], rango[tam], n, m;

int encontrar_papa(int i)
{
	return (papa[i] == i) ? i: ( papa[i] = encontrar_papa( papa[i] ) );
}

void unir(int pi, int pj)
{
	//int pi = encontrar_papa(i), pj = encontrar_papa(j);
	//if (pi==pj) return;

	if (rango[pi]> rango[pj])
		papa[pj] = pi;
	else
	{
		papa[pi] = pj;
		if ( rango[pi]==rango[pj] ) ++rango[pj];
	}

}

int main()
{
	int u, v, pi,pj;
	ll w;//, peso_graf, peso_arbol;
	while (cin>>n>>m and n)
	{
		//peso_arbol = peso_graf = 0;
		omitidos.clear();
		ListaAristas.clear();

		for (int i = 0; i < n; ++i)
			papa[i] = i, rango[i] = 0;

		while (m--)
		{
			cin>>u>>v>>w;			
			ListaAristas.push_back( mk(w, mk(u,v) ) );

			//peso_graf += w;
		}

		sort(ListaAristas.begin(), ListaAristas.end());
		
		for (auto &e:ListaAristas)
		{
			w = e.first; u = e.second.first; v = e.second.second;
			pi = encontrar_papa(u); pj = encontrar_papa(v);
			if (pi == pj)			
				omitidos.push_back(w);			
			else
			{
				unir(pi, pj);
				//peso_arbol += w;
			}
		}

		if (omitidos.size())
		{
			cout<<omitidos[0];
			for (int j = 1; j<omitidos.size(); ++j)
				cout<<" "<<omitidos[j];
		}
		else cout<<"forest";
		cout<<"\n";

	}
	return 0;
}