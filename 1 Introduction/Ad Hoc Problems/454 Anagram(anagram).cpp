#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	int t, i, j, comparador[200][300], k, w, pep=0;
	bool b;
	string sb, arreglo[200], s;
	scanf("%d", &t);
	getline(cin, sb);		//se escanean(getline) dos lineas de basura
	getline(cin, sb);		//una es el salto de linea del numero de casos
	while(t--)				//y la otra es la linea en blanco
	{
		i=0;
		while(getline(cin, s) && s!=sb)	//mientras no llegue a una linea en blanco
		{	
			arreglo[i]=s;				//agregar las oraciones a mi lista de palabras
			++i;						//saber cuantas tengo
		}

		sort(arreglo, arreglo+i);		//la impresion debe ser lexicografica, le aplico un sort a mi lista

		memset(comparador, 0, sizeof comparador);	//para cada caso de prueba limpio el arreglo que me dira cuantas y cuales letras
													//tiene cada oracion

		for (j=0; j<i; ++j)							//para cada oracion
			for (k=0; k<arreglo[j].size(); ++k)		//recorrerla
				++comparador[j][ arreglo[j][k] ];	//comparador(oracion j)( en su posicion 'a' o 'b'), aumenta el contador

		for (j=0; j<i; ++j)					//comparar todas contra todas
			for (k=j+1; k<i; ++k)
			{
				b=true;						//supongo que las oraciones j y k son "iguales"
				for (w=' '+1;w<=255;++w)	
					if (comparador[j][w]!=comparador[k][w])	//si son diferentes lo indico
					{
						b=false;
						break;
					}
				if (b==true)	//si son iguales, imprimo
					cout<<arreglo[j]<<" = "<<arreglo[k]<<endl;					
			}

		if (t) cout<<endl;			// si no es el ultimo caso, imprimo para separar los casos
	}
	return 0;
}