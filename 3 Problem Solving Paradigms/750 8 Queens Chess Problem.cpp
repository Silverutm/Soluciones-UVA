#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
int rs, cs, sol[10], lineas;
bitset <20> rows, d1, d2;

void buscar(int c)
{
	if (c==9 and sol[cs]==rs )
	{
		printf("%2d     ", ++lineas);
		for (int i=1; i<=8; ++i)
			printf(" %d",sol[i] );
		printf("\n");
	}
	else
	for (int i=1; i<=8; ++i)
	{
		//si la diagonal fila, y diagonales donde
		//quiero poner a la reina esta desocupado
		if ( !rows[i] and !d1[i+c] and !d2[i-c+8] )
		{
			//las ocupo
			rows[i] = d1[i+c] = d2[i-c+8]=true;
			sol[c]=i; //lo pongo en la posible solucion
			
			buscar(c+1);	//me paso a la siguiente columna
			
			//la desocupo para intentar poner otra reina en
			//la misma columna
			rows[i] = d1[i+c] = d2[i-c+8]=false;	
		}
	}
	return ;
}

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>rs>>cs;
		d1.reset();
		d2.reset();
		rows.reset();
		
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		lineas=0;
		
		buscar(1);

		//un salto de linea entre cada caso
		if (t) printf("\n");
	}
	return 0;
}