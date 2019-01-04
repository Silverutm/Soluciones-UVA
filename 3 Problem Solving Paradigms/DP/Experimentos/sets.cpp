#include <iostream>
#include <set>		//libreria donde se encuentran los sets
using namespace std;
int main()
{
	int i;
	//set <Tipo_ded_Dato> miset
	set <int> miset;

	//agregar elementos
	for (i=0; i<6; ++i)
		miset.insert( i );

	//si intentamos insertar un elemento
	//que ya existe, no pasa nada
	for (i=-1; i<7; ++i)
		miset.insert( i );

	//saber si un elemento existe
	if ( miset.find( 4 )!=miset.end() )
		cout<<"Encontrado\n";

	//eliminar un elemento
	miset.erase( miset.find( 5 ) );
	//si no existe explota  //ver antes si existe
	//miset.erase( miset.find( 10 ) );

	//ver sus elementos
	for (auto s:miset)
		cout<<s<<" ";
	return 0;
}