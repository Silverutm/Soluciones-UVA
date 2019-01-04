#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
int durmientes;
char x;
int papa[300], rango[300];
vector <int> Lista[300], a_unir;
int encontrar_papa(int i)
{
	return (papa[i] == i ) ? i:( papa[i]=encontrar_papa( papa[i] ) );
}

void unir(int i, int j)
{
	int pi = encontrar_papa(i), pj = encontrar_papa(j);
	if ( pi==pj ) return;

	if (rango[pi]>rango[pj])	
		papa[pj] = pi;
	else
	{
		papa[pi] = pj;
		if (rango[pi] == rango[pj] ) ++rango[pj];		
	}
}

bool revisar(int i)
{
	if (Lista[i].size()<3) return false;
	int px = encontrar_papa(x), contador=0;
	for (auto & e:Lista[i])
		if (encontrar_papa(e)==px)
			++contador;
	if (contador>=3)
	{
		//unir(i, px);
		a_unir.push_back(i);
		return true;
	}
	return false;
}

int main()
{
	string despiertos, s;	
	bool cambios;
	int veces, m;
	bitset <500> visitados;
	while(cin>>durmientes)
	{		
		for (int i = 0; i < 300; ++i)
		{
			rango[i] = 0;
			papa[i] = i;			
		}

		for (int i = 'A'; i <= 'Z'; ++i)
			Lista[i].clear();
		visitados.reset();
		cin>>m;
		cin>>despiertos;
		x = despiertos[0];
		for (int i = 1; i < despiertos.size(); ++i)
			unir( x, despiertos[i] );
		for (auto &e: despiertos) visitados[e] = true;
		while (m--)
		{
			cin>>s;
			Lista[ s[0] ].push_back( s[1] );
			Lista[ s[1] ].push_back( s[0] );
		}
		cambios = true;
		int cantidad=0;
		veces = 0;
		if ( despiertos.size()!=durmientes )
		for ( veces = 0; veces < 30 and cambios; ++veces)
		{
			cambios = false;
			for (int i = 'A'; i <= 'Z'; ++i)
			{
				if ( visitados[i] ) continue;
				if ( revisar(i) )
				{
					cambios = true;
					visitados[i] = true;
					++cantidad;
				}
			}
			for (auto & e:a_unir) unir(x, e);
			a_unir.clear();
		}
		if (cantidad + despiertos.size()==durmientes)
			cout<<"WAKE UP IN, "<< max(0,veces-1)<<", YEARS\n";
		else cout<<"THIS BRAIN NEVER WAKES UP\n";
		//cout<<cantidad<<endl;
	}
	return 0;
}