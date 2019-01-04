#include <iostream>
#include <map>
#define tam 200005
using namespace std;
map <string, int> mapa;
int personas;
int papa[tam], rango[tam], cantidad[tam];

int encontrar_papa(int i)
{
	return ( papa[i] == i ) ? i: ( papa[i] = encontrar_papa(papa[i]) );
}

int unir(int i, int j)
{
	int pi = encontrar_papa(i), pj = encontrar_papa(j);
	if (pi == pj) return cantidad[pj];

	if (rango[pi] > rango[pj])
	{
		papa[pj] = pi;
		cantidad[pi] += cantidad[pj];
		return cantidad[pi];
	}
	else
	{
		papa[pi] = pj;
		if (rango[pi] == rango[pj] ) ++rango[pj];
		cantidad[pj] += cantidad[pi];
		return cantidad[pj];
	}
	return 0;
}

int main()
{
	int casos, id1, id2, f;
	string s1, s2;
	cin>>casos;
	while (casos--)
	{
		personas = 1;
		mapa.clear();
		for (int i = 0; i < tam; ++i)
		{
			rango[i] = 0;
			papa[i] = i;
			cantidad[i] = 1;
		}

		cin>>f;
		while (f--)
		{
			cin>>s1>>s2;
			if ( not ( id1 = mapa[s1] ) )
				id1 = mapa[s1] = personas++;
			if ( not ( id2 = mapa[s2] ) )
				id2 = mapa[s2] = personas++;

			cout<<unir(id1, id2)<<"\n";
		}
	}
	return 0;
}