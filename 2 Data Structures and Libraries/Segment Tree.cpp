#include <iostream>
using namespace std;
#define tam 500
int arreglo[tam], segment_tree[tam*4],i, j;

int hijo_izquierdo(int p)
{ return p << 1; }

int hijo_derecho(int p)
{ return (p<<1) + 1; }

void construir(int p, int izq, int der)
{
	if (izq == der)
		segment_tree[p] = izq;
	else 
	{
		construir( hijo_izquierdo(p), izq, (izq+der)/2 );
		construir( hijo_derecho(p), (izq+der)/2+1, der );
		
		int p1 = segment_tree[ hijo_izquierdo(p) ], 
			p2 = segment_tree[ hijo_derecho(p) ];

		segment_tree[p] = (arreglo[p1] <= arreglo[p2] ) ? p1:p2;
	}
}

int rmq( int p, int izq, int der )
{
	if (i > der or j<izq) return -1;	//nos salimos del rango
	if (izq >= i and der <= j) return segment_tree[p];	//estamos completamente
													//dentro del rango

	int p1 = rmq(hijo_izquierdo(p), izq, (izq+der)/2),
		p2 = rmq(hijo_derecho(p), (izq+der)/2+1, der);

	if (p1 == -1) return p2;
	if (p2 == -1 ) return p1;

	return (arreglo[p1]<= arreglo[p2]) ? p1:p2;
}

int main()
{
	int n, q;
	cin>>n;
	for ( i = 0; i < n; ++i)
		cin>>arreglo[i];

	for ( i = 0; i < 4*n; ++i)
		segment_tree[i] = 0;

	construir(1, 0, n - 1);

	cin>>q;
	while (q--)
	{
		cin>>i>>j;
		cout<<rmq(1,0, n-1)<<"\n";
	}
	return 0;
}