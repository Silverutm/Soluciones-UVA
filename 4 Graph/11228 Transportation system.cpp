#include <bits/stdc++.h>
#define mk make_pair
#define tam 1005
using namespace std;
//typedef lo ll;
vector <pair< double, pair<int, int> > > ListaAristas;
vector <pair<double, double>> V;
set <int> conjunto;
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

double dist(pair<double, double> a, pair<double, double> b)
{
	return sqrt( (a.first - b.first)*(a.first - b.first) +
				 (a.second - b.second)*(a.second - b.second) );
} 

int main()
{
	int t, i, u, v, pi, pj, r;
	double x, y, peso_arbol1, peso_arbol2, w;
	cin>>t;
	for (int caso = 1; caso <= t; ++caso)
	{
		ListaAristas.clear();
		V.clear();

		cin>>n>>r;
		for ( i = 0; i < n; ++i)
		{
			cin>>x>>y;
			V.push_back(mk(x,y));
			papa[i]=i;
			rango[i]=0;
		}

		for ( i = 0; i < n; ++i)
			for (int j = i+1; j < n; ++j)
				ListaAristas.push_back( mk(dist(V[i], V[j]), mk(i,j) ) );

		sort(ListaAristas.begin(), ListaAristas.end());
		m = ListaAristas.size();
		peso_arbol1=peso_arbol2 = 0;
		for ( i = 0; i < m and ListaAristas[i].first<=r ; ++i)
		{
			auto e = ListaAristas[i];
			w = e.first; u = e.second.first; v = e.second.second;
			pi = encontrar_papa(u); pj = encontrar_papa(v);
			
			if (pi != pj)			
			{
				unir(pi, pj);
				peso_arbol1 += w;
			}
		}
		//cout<<"hoooooooooooo\n";
		conjunto.clear();
		/*for (int j = 0; j < n; ++i)
			cout<<papa[j]<<" ";
		cout<<"\n";*/
		for (int j = 0; j < n; ++j)
		{
			int z = encontrar_papa(j);
			//if ( z!=j)
				conjunto.insert(z);
		}
		//cout<<"hoooooooooooo..\n";
		for ( ; i < m ; ++i)
		{
			auto e = ListaAristas[i];
			w = e.first; u = e.second.first; v = e.second.second;
			pi = encontrar_papa(u); pj = encontrar_papa(v);
			
			if (pi != pj)			
			{
				unir(pi, pj);
				peso_arbol2 += w;
			}
		}
		cout<<"Case #"<<caso<<": "<<conjunto.size()<<" "<<
				int(peso_arbol1+.5)<<" "<<int(peso_arbol2+.5)<<"\n";
	}
	return 0;
}