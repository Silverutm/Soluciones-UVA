#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int sumarcaracteres(string cadena)
{
	int i, respuesta = 0;
	for (i=0; i< cadena.size(); i++)
	{
		if (cadena[i]>='a' and cadena[i]<='z')
			respuesta += cadena[i]-'a' + 1;
		else if (cadena[i]>='A' and cadena[i]<='Z')
			respuesta += cadena[i]-'A' + 1;
	}
	return respuesta;
}

int sumardigitosde(int x)
{
	int suma;
	while( x>=10 )
	{
		suma = 0;
		while (x>0)
		{
			suma += x % 10;
			x /= 10;	
		}
		x = suma;
	}
	return x;
}

int main()
{
	string linea1, linea2;
	int x1, x2;
	float porcentaje;
	while( getline(cin, linea1) and getline(cin, linea2) )
	{
		x1 = sumarcaracteres( linea1 );
		x2 = sumarcaracteres( linea2 );

		x1 = sumardigitosde( x1 );
		x2 = sumardigitosde( x2 );
		if (x1> x2) porcentaje = x2/(float)x1;
		else porcentaje = x1/(float)x2 ;
		printf("%.2f %%\n", porcentaje*100  );
	}
	return 0;
}