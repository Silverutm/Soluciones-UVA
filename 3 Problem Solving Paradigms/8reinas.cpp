#include <iostream>
#include <cstdio>
using namespace std;
int filas=0, reinas[10], diagonal1=0, diagonal2=0;

void imprimir()
{
	for (int i=0; i<8; ++i)
		printf("%d ",reinas[i]+1 );
	printf("\n");
}

void busqueda(int c)
{
	if (c==8) imprimir();
	for ( int r=0; r<8; ++r)
	{
		if ( filas & (1<<r) )
			continue;
		if (diagonal1 & (1<<c-r+8) )
			continue;
		if (diagonal2 & (1<<c+r) )
			continue;

		filas |=(1<<r);
		diagonal1 |=(1<<c-r+8);
		diagonal2 |=(1<<c+r);

		reinas[c]=r;
		busqueda(c+1);

		diagonal1 &=~(1<<c-r+8);
		diagonal2 &=~(1<<c+r);
		filas &=~(1<<r);
	}
}

int main()
{
	for (int i=0;i<8; ++i)
		printf("%d ", i+1);
	printf("\n");
	busqueda( 0 );
	return 0;
}