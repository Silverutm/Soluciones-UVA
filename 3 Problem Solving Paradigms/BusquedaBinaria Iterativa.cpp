#include <iostream>
#include <algorithm>
using namespace std;

vector <int> v;
int elementobuscado;

//intervalo [ ini, fin ]
//Idea de Maza
bool busqueda(int ini, int fin)
{
	int mitad;
	while (1)
	{
		mitad=( ini+fin )/2;
		if ( v[mitad]==elementobuscado )
			return true;
		if ( fin<=ini ) return false;

		if ( v[mitad]<elementobuscado )
			ini = mitad+1;
		else fin = mitad-1;
	}
}

int main()
{
	int ini, fin, a;
	while (cin>>a)
		v.push_back(a);
	sort(v.begin(), v.end());

	ini=0; fin=v.size()-1;
	elementobuscado=5;

	if ( binary_search(v.begin(), v.end(), elementobuscado) )
		cout<<"Encontrado\n";
	else cout<<"No Encontrado\n";

	//indice donde se encontro el elemento
    auto iterador = find( v.begin(), v.end(), elementobuscado );
    if (iterador != v.end() )
        cout<<"Esta en el indice: "<<iterador - v.begin()<<endl;

    //un iterador que apunta al menor "numero"
    // que no es menor al elemento buscado
    auto mi_iterador = lower_bound( v.begin(), v.end(), elementobuscado );
	cout<<"# de Elementos menores a "<< elementobuscado<<endl
		<<mi_iterador - v.begin()<<endl;    
    

    //un iterador que apunta al menor "numero"
    // que es mayor al elemento buscado
    auto mo_iterador = upper_bound( v.begin(), v.end(), elementobuscado );
    cout<<"# de Elementos menores o iguales a "<< elementobuscado<<endl
		<<mo_iterador - v.begin()<<endl;

	return 0;

	if ( busqueda(ini, fin) )
		cout<<"Encontrado\n";
	else cout<<"No Encontrado\n";

	return 0;
}