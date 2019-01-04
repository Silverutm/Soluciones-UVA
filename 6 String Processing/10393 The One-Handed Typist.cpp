#include <iostream>
#include <vector>
#include <bitset>
#include <set>
#include <algorithm>
using namespace std;
vector < pair<int, string> > palabras;
bitset <13> posibles;
bitset <500> letras;
string dedos[] = {"", "qaz", "wsx", "edc", "rftvgb", "", 
	"", "yhnujm", "ik", "ol", "p"};
string s;
bool f(pair<int, string> a, pair<int, string> b)
{
	return a.first > b.first;
}
set <string> respuestas;

bool ver(string cad)
{
	bool r= true;
	for (auto e: cad)
		r = r and letras[e];
	return r;
}
int main()
{
	int a, d , p, tam;
	while (cin>>d>>p)
	{
		posibles.set();
		letras.reset();
		respuestas.clear();
		palabras.clear();
		while (d--)
		{
			cin>>a;
			posibles[a] = false;
		}
		for (int i = 1; i <= 10; ++i)
			if ( posibles[i] )
				for ( auto c: dedos[i] )
					letras[c] = true;
		while (p--)
		{
			cin>>s;
			palabras.push_back( make_pair( s.size(), s ) );
		}
		sort ( palabras.begin(), palabras.end(), f );
		tam = palabras[0].first;
		int i=0;
		while ( respuestas.empty()  and i<palabras.size() )
		{

			while (i<palabras.size() and tam==palabras[i].first )
			{
				if ( ver(palabras[i].second) )
					//respuestas.push_back( palabras[i].second );
					respuestas.insert( palabras[i].second );
				++i;
			}
			tam = palabras[i].first;
		}
		cout<<respuestas.size()<<endl;
		//sort(respuestas.begin(), respuestas.end());
		for (auto cad:respuestas)
			cout<<cad<<endl;

	}
	return 0;
}
