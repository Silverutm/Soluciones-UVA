#include <bits/stdc++.h>
using namespace std;
string s;
#include "funciones/funciones.h"
//#include "/funciones/algo00.h"
//#include "/funciones/Algo00_Tabla_Mult.h"
//#include "/funciones/algo02.h"
//#include "/funciones/sum.h"
//#include "/funciones/tabla.h"
//#include "/funciones/tablas.h"
#include "algoritmos.h"
using namespace std;
int cantidades[10];
int total;


bool tiene_alfa()
{
	for (auto &e:s)
		if ( isalpha(e) )
			return true;
	return false;
}

void todos()
{	
	if ( no_es_algoritmo_00() )
	{
		if ( no_es_algoritmo_02() )
		{
			if ( no_es_algoritmo_03() )
			{
				if ( no_es_algoritmo_04() )
				{
					if ( no_es_algoritmo_06() )
					{
						if ( no_es_algoritmo_35() )
						{
							if ( no_es_algoritmo_36() )
							{
								if ( no_es_algoritmo_37() )
								{
									++cantidades[8];
								}
								else
									++cantidades[7];
							}
							else
								++cantidades[6];
						}
						else
							++cantidades[5];
					}
					else
						++cantidades[4];
				}
				else
					++cantidades[3];
			}
			else
				++cantidades[2];
		}
		else
			++cantidades[1];
	}
	else
		++cantidades[0];
}


void los_que_tienen_alfa()
{
	if ( no_es_algoritmo_02() )
	{
		if ( no_es_algoritmo_35() )
		{
			if ( no_es_algoritmo_36() )
			{
				if ( no_es_algoritmo_37() )
				{
					++cantidades[8];
				}
				else
					++cantidades[7];
			}
			else
				++cantidades[6];
		}
		else
			++cantidades[5];
	}
	else
		++cantidades[1];
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	while ( cin>>s )
	{
		++total;
		ultimo_char = s[ s.size()-1 ];
		if ( tiene_alfa() )
			los_que_tienen_alfa();
		else
			todos();
	}

	printf("var cantidad = [");
	printf("%d", cantidades[0]);
	for (i = 1; i < 9; ++i)
		printf(", %d", cantidades[i]);
	printf("];\n\n");

	printf("var porcentajes = [");
	printf("%lf", cantidades[0]*100/(double)total);
	for (i = 1; i < 9; ++i)
		printf(", %lf", cantidades[i]*100/(double)total);
	printf("];\n\n");
	return 0;
}


/*
var algoritmos = ["00", "02", "03", "04", "06", "35", "36", "37", "Error"];
var cantidad = [20000000, 15000000, 10000000, 10000000, 5000000, 4000000, 1000000, 0, 15000000];
var porcentajes = [10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 20.0, 10.0];


*/