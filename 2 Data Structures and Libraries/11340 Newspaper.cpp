#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
double arreglo[1000];

string residuo(int a)
{
	if (a<10) return "0";
	return "";
}

int main()
{
	int casos, lineas, pagadas;
	double valor, total;
	char letra;
	string cadena;
	cin>>casos;
	while (casos--)
	{
		memset (arreglo, 0, sizeof arreglo);
		total = 0;

		cin>>pagadas;
		while (pagadas--)
		{
			cin>>letra>>valor;
			arreglo[letra]=valor;
		}

		cin>>lineas;
		getline(cin, cadena);
		while (lineas--)
		{
			getline(cin, cadena);			
			for (auto & c:cadena)
				total += arreglo[c];
		}		
		printf("%0.2lf$\n", total/100.0);		
	}
	return 0;
}