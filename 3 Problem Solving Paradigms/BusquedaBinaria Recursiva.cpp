#include <iostream>
#include <algorithm>
using namespace std;

vector <int> v;
int elementobuscado;

//intervalo [ ini, fin ]
bool busqueda(int ini, int fin)
{
	int mitad=( ini+fin )/2;
	if ( v[mitad]==elementobuscado )
		return true;
	if ( fin<=ini ) return false;

	if ( v[mitad]<elementobuscado )
		return busqueda(mitad+1, fin);
	else return busqueda(ini, mitad-1);
}

int main()
{
	int ini, fin, a;
	while (cin>>a)
		v.push_back(a);
	sort(v.begin(), v.end());

	ini=0; fin=v.size()-1;
	elementobuscado=5;

	if ( busqueda(ini, fin) )
		cout<<"Encontrado\n";
	else cout<<"No Encontrado\n";

	return 0;
}