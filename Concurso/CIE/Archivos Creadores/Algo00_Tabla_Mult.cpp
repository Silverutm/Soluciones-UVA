#include <iostream>
#include <cstdio>
using namespace std;
short tabla[500][3];
short tabla_Dif_decena[185];
short suma_de_digitos(short a)
{
	short res = 0;
	while (a!= 0)
	{
		res += a%10;
		a /= 10;
	}
	return res;
}



void imprimir()
{
	printf("short Tabla_00_Convertir_dig[%d][3] = { ",'9'+2 );
	for (int j = 0; j < 3; ++j)
	{
		printf("{" );
		for (int i = 0; i <= '9'; ++i)
		{
			printf("%d, ", tabla[i][j] );
		}
		printf("0 },\n" );
	}
	printf("};\n");

	}


short calcula_dif_decena(short a)
{
	short res = 0;
	res=(10-a%10)%10;
	return res;
}

void imprimirDifDecena(){

	printf("short Tabla_00_Dif_decena[] = {");
	for (int i = 0; i < 180; ++i)
	{
		printf("%d,",calcula_dif_decena(i));
	}
	printf("0};\n");

}

int main()
{
	for (int i = '0'; i <= '9'; ++i)
	{
		tabla[ i ][1] = i-'0';
		tabla[ i ][2] = suma_de_digitos( (i-'0')*2 );
	}
	imprimir();

	for (int k = 0; k < 180; ++k)
	{
		tabla_Dif_decena[ k ] = calcula_dif_decena(k);
	}
	imprimirDifDecena();

	return 0;
}
