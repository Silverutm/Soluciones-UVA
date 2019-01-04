#include <iostream>
#include <array>
#include <cstdio>
#include <bitset>
using namespace std;
#define tam 100005
int segment_tree[ 4*tam ][10], cambio[4*tam][10], arreglo[tam][10], comodin[10];
bitset < 4*tam > necesita_cambio;
int i, j, op;
string s;

int hi(int p)
{ return p<<1; }

int hd(int p)
{ return (p<<1) + 1; }

void convertir(int  arr[] )
{
	for (int w = 0; w < 10; ++w)
		arr[w] = 0;
	for (auto &e:s)
		++arr[ e-'0' ];

}

void igualar(int arr1[], int arr2[], int w)
{
	for (int z = 0; z < 10; ++z)
		arr1[z] = arr2[z] * w;
}

void sumar(int arr1[], int arr2[], int arr3[])
{
	for (int i = 0; i < 10; ++i)
		arr1[i] = arr2[i] + arr3[i];
}

void construir(int p, int izq, int der)
{
	if ( izq == der );
	{
		igualar( segment_tree[p], arreglo[izq], 1 );
		return;
	}
	construir( hi(p), izq, (izq+der)/2 );
	construir( hd(p),(izq+der)/2+1, der );

	sumar( segment_tree[p], segment_tree[ hi(p) ], segment_tree[ hd(p) ] );
}

void propagar(int p, int izq, int der)
{
	if (not necesita_cambio[p]) return;

	igualar( segment_tree[p], cambio[p], der- izq + 1 );

	if (izq != der )
	{
		necesita_cambio[hi(p)] = necesita_cambio[hd(p)] = true;
		igualar ( cambio[hi(p)], cambio[p], 1 );
		igualar ( cambio[hd(p)], cambio[p], 1 );
	}
	necesita_cambio[p] = false;
}

void actualizar(int p, int izq, int der)
{
	propagar( p, izq, der);
	if (i > der or j <izq) return;

	if (izq == der)
	{
		igualar( segment_tree[p], comodin, der - izq +1);
		return;
	}

	if (izq >= i and der <= j)
	{
		igualar( segment_tree[p], comodin, der - izq +1);
		necesita_cambio[hi(p)] = necesita_cambio[hd(p)] = true;
		igualar ( cambio[hi(p)], comodin, 1 );
		igualar ( cambio[hd(p)], comodin, 1 );
	}

	actualizar (hi(p), izq, (izq+der)/2);
	actualizar (hd(p), (izq+der)/2 +1, der);

	sumar( segment_tree[p], segment_tree[ hi(p) ], segment_tree[ hd(p) ] );
	
}
array <int, 10> cero;
array <int, 10> consulta(int p, int izq, int der)
{
	if (i >der or j <izq) return cero;
	propagar(p, izq, der);
	array <int, 10> res;
	if (izq >= i and der <= j)
	{
		for (int w = 0; w < 10; ++w)
			res[w] = segment_tree[p][w];
		return res;	
	}
	array <int, 10> q1= consulta (hi(p), izq, (izq+der)/2),
					q2= consulta (hd(p), (izq+der)/2 + 1, der);
	for (int w = 0; w< 10; ++w)
		q1[w] += q2[w];
	return q1;
}

int main()
{
	int n, k;	
	scanf( "%d %d", &n, &k);
	for ( i = 0; i < n; ++i)
	{
		cin>>s;
		convertir( arreglo[i] );
	}
	necesita_cambio.reset();
	construir(1, 0, n-1);

	while (k--)
	{		
		scanf( "%d %d %d", &op, &i, &j);
		--i; --j;
		if (op)
		{
			cin>>s;
			convertir( comodin );
			actualizar(1, 0, n-1);
		}
		else 
		{
			//int arr[10] = consulta(1, 0, n-1);
			array <int, 10> res = consulta(1, 0, n-1);
			int ind=0;
			for (int w = 1; w < 10; ++w)
				printf("%d: %d\n",w, res[w] );
				//if ( res[w]>res[ind] ) ind = w;
			//printf("%d: %d\n",ind, res[ind] );
			printf("\n");
		}

	}	
	
	return 0;
}