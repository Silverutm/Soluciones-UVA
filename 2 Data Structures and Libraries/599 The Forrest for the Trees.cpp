#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
vector <int> Lista[30];
bitset <30> mi_bitset;
void buscar(int a)
{
	mi_bitset[a] = true;
	for (auto & e: Lista[a])
		if ( not mi_bitset[e] )
			buscar(e);
}
int main()
{
	int casos, arboles, puntos;
	string arista;
	cin>>casos;
	while (casos--)
	{
		mi_bitset.set();
		arboles = puntos = 0;

		for (int i = 0; i < 30; ++i)
			Lista[i].clear();

		while(cin>>arista and arista[0]!='*')
		{
			Lista[ arista[1]-'A' ].push_back( arista[3]-'A' );
			Lista[ arista[3]-'A' ].push_back( arista[1]-'A' );
		}
		cin>>arista;
		for (int i = 0; i < arista.size(); i += 2)
			mi_bitset[ arista[i] -'A' ] = false;
		for (int i = 'A'; i <= 'Z'; ++i)
		{
			if ( mi_bitset[i-'A'] ) continue;
			if ( Lista[i-'A'].empty() ) ++puntos;
			else
			{
				++arboles;
				buscar(i-'A');
			}
		}
		cout<<"There are "<<arboles <<" tree(s) and "<< puntos <<" acorn(s).\n";
	}
	return 0;
}