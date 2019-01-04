#include <iostream>
#include <cstdlib>
using namespace std;
#define tam 100005
int i, j;
int arreglo[tam], segment_tree[tam*4];
int normalizar(int a)
{
	if (a) return a/abs(a);
	return 0;
}
int hi(int p)
{ return p<<1; }

int hd(int p)
{ return (p<<1) + 1; }

void construir(int p, int izq, int der)
{
	if ( izq == der ) 
	{
		segment_tree[p] = arreglo[ izq ];
		return;
	}

	construir( hi(p), izq, (izq+der)/2 );
	construir( hd(p), (izq+der)/2 +1, der );

	segment_tree[p] = segment_tree[ hi(p) ] * segment_tree[ hd(p) ];
}

int consulta(int p, int izq, int der)
{
	if ( i > der or j < izq ) return 1;

	if ( izq >= i and der <= j )
		return segment_tree[p];

	int q1 = consulta( hi(p), izq, (izq + der)/2 ),
		q2 = consulta( hd(p), (izq + der)/2 + 1, der );

	return q1 * q2;
}

int actualizar(int p, int izq, int der)
{
	if (i>der or i< izq) return segment_tree[p];

	if ( izq == der )
		return segment_tree[p] = j;	

	int q1 = actualizar( hi(p), izq, (izq + der)/2 ),
		q2 = actualizar( hd(p), (izq + der)/2 + 1, der );

	return segment_tree[p] =  q1 * q2;	
}

void imprime(int a)
{
	if (a>0) cout<<"+";
	else if (a<0) cout<<"-";
	else cout<<a;
}

int main()
{
	int n, k,a;
	char c;
	while (cin>>n>>k)
	{
		for (i = 0; i < n; ++i)
		{
			cin>>a;
			arreglo[i] = normalizar( a );			
		}

		construir( 1, 0, n - 1 );

		while (k--)
		{
			cin>>c>>i>>j;
			--i;
			if (c=='C')
			{
				j = normalizar( j );
				if ( j!= arreglo[i] )
					actualizar( 1, 0, n - 1 );
				arreglo[ i ] = j;
			}
			else
			{ 
				--j; 
				imprime ( consulta(1, 0, n - 1) ); 
			}
		}
		cout<<"\n";
	}
	return 0;
}
