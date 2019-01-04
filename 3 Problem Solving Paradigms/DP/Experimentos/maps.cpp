#include <iostream>
#include <map>
using namespace std;
int main()
{
	map <string , int> mapa;

	//ingresar elementos
	mapa["cadena1"]=23;
	//si no le asignamos ningun valor y no existe
	//le asignara el 1 por default
	mapa["otra cadena"];

	//podemos ver su valor de la siguiente manera
	cout<<mapa["cadena1"]<<endl;

	//podemos incrementar valores
	++mapa["cadena que quiza no exista"];

	//ver sus elementos
	//cada elemento de un mapa es un pair
	//el .first es el indice
	//el .second el valor mapa[indice]
	for (auto par:mapa )
		cout<<par.first<<" "<<par.second<<endl;
	return 0;
}