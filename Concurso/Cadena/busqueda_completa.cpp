#include <bits/stdc++.h>
using namespace std;
vector <int> Termina_con[500], Lista[250];
vector <string> Palabras;
vector <int> res, v_final;
int total, n, final;
bitset <250> visitados;
void busqueda_completa(int v)
{
	visitados[v] = true;	
	total += Palabras[v].size() - 1;
	res.push_back( v );

	bool hubo_cambio = false;
	for (auto &u: Lista[v])
	{
		if (visitados[u]) continue;
		busqueda_completa(u);
		hubo_cambio = true;
	}
	visitados[v] = false;
	total -= Palabras[v].size() - 1;
	res.pop_back();

	if ( not hubo_cambio )
	{
		if (total > final)
		{
			v_final = res;
			final = total;
			cout<<final<<endl;
			for (auto &v:v_final)
				cout<<Palabras[v]<<"\n";
			printf("\n\n");
		}
	}
}
int main()
{
	int fin, i, ini;
	string s;
	i = 0;	
	visitados.reset();
	while ( getline(cin,s) )
	{
		fin = s[ s.size() -1 ] = tolower(s[ s.size() -1 ]);
		if (fin == 'x') continue;
		s[0] = tolower( s[0] );		
		
		Palabras.push_back( s );
		Termina_con[fin].push_back( i );
		++i;
	}

	i = 0;
	for ( auto &s:Palabras )
	{
		ini = s[0];
		for ( auto e:Termina_con[ini] )
			Lista[e].push_back(i);
		++i;
	}

	/*for (int i = 0; i < Palabras.size(); ++i)
	{
		cout<<Palabras[i]<<"\n";
		for (int j = 0; j < Lista[i].size(); ++j)
			cout<<Palabras[ Lista[i][j] ]<<"\n";
		cout<<"\n\n";
	}*/
	final = total = 0;
	n=Palabras.size();

	for (int i = 0; i < n; ++i)
	{		
		busqueda_completa(i);
	}
	
	return 0;
}