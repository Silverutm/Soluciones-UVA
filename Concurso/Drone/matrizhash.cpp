/*
Crea una matriz de hashes, suponiendo que la palabra mas grande sera de 30 caracteres
y que solo hare hash de la primera y ultima palabra
esta cosa no utilizara un rolling hash
*/
#include <bits/stdc++.h>
using namespace std;
//sirven para el hash
#define Tam 151
typedef unsigned long long ull;
ull modulo1 = 10000000000000061, modulo2 = 10000000000000069;
ull primo1=257, primo2=263;
ull MatrizHash1[256][Tam], MatrizHash2[256][Tam];
ull potencias1[Tam], potencias2[Tam];
int main()
{
	ull i, j;

	//preproceso
	potencias1[0]=potencias2[0]=1;
	for (j = 0; ++j<Tam; )
	{
		potencias1[ j ] = ( potencias1[ j-1 ]*primo1 )%modulo1;
		potencias2[ j ] = ( potencias2[ j-1 ]*primo2 )%modulo2;
	}

	//hashear cada letra
	for (i=30; ++i<256; )
		for (j=-1; ++j<Tam; )
		{
			MatrizHash1[i][j]= ( i * potencias1[ j ] ) % modulo1;
			MatrizHash2[i][j]= ( i * potencias2[ j ] ) % modulo2;
		}


	//imprimir la matriz
	cout<<"ull MatrizHash1[256]["<<Tam<<"] = { ";
	for (i=-1; ++i<256; )
	{
		cout<<" { "<<MatrizHash1[i][0];
		for (j=0; ++j<Tam; )
			cout<<" , "<<MatrizHash1[i][j];
		cout<<" }, \n";
	}
	cout<<" };\n\n\n";

	cout<<"ull MatrizHash2[256]["<<Tam<<"] = { ";
	for (i=-1; ++i<256; )
	{
		cout<<" { "<<MatrizHash2[i][0];
		for (j=0; ++j<Tam; )
			cout<<" , "<<MatrizHash2[i][j];
		cout<<" }, \n";
	}
	cout<<" };\n\n\n";
	return 0;
}
