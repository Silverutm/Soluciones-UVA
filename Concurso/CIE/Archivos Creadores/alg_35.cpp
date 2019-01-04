#include <iostream>
#include <cstdio>
using namespace std;
short tabla[500];

void imprimir(){

	printf("short Tabla_35_letra_a_numero[] = {");
	for (int i = 0; i < 'Z'+3; ++i)
	{
		printf("%d,",tabla[i]);
	}
	printf("0};\n");

}

int main()
{
	for (int i = '0'; i <= 'Z'; ++i)
	{
		tabla[ i ] = i-'0';
	}

	for (int i = 'A'; i <= 'Z'; ++i)
	{
		tabla[ i ] = i-'A' + 1 ;
	}

	imprimir();


	return 0;
}
