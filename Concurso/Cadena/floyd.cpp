#include <bits/stdc++.h>
using namespace std;
vector <int> Termina_con[500], Lista[250];
vector <string> Palabras;
vector <int> res, v_final;
int total, n, final;
bitset <250> visitados;

int AdjMat[250][250];

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
	
	//memset(AdjMat, -1,sizeof AdjMat);
	for (int i = 0; i < 200; ++i)
	{
		for (int j = 0; j < 200; ++j)
			AdjMat[j][j] = 100000000;
	}
	for (int i = 0; i < n; ++i)
	{
		for (auto &v: Lista[i])
		{
			AdjMat[i][v] = Palabras[v].size() - 1;
		}
	}

	for (int k = 0; k < n; k++) // remember that loop order is k->i->j
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

	int po=0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		po = max(po, AdjMat[i][j]);
	cout<<po<<endl;
	return 0;
}