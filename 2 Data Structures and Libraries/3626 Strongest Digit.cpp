#include <iostream>
#include <array>
#include <cstdio>
#include <bitset>
using namespace std;
#define tam 100005
array<int, 10> segment_tree[ tam<<2 ], cambio[tam<<2], arreglo[tam], comodin;
bitset < tam<<2 > necesita_cambio;
int i, j, op;
string s;

int hi(int p)
{ return p<<1; }

int hd(int p)
{ return (p<<1) + 1; }

array <int, 10> cero;
array<int, 10> convertir( )
{
	array<int, 10> arr;
	arr = cero;	
	for (auto &e:s)
		++arr[ e-'0' ];
	return arr;
}

array<int, 10> igualar(array<int, 10> arr, int w)
{
	for (int z = 0; z < 10; ++z)
		arr[z] *=  w;
	return arr;
}

array<int, 10> sumar(array<int, 10> arr, array<int, 10> arr1)
{
	for (int w = 0; w < 10; ++w)
		arr[w] += arr1[w];
	return arr;
}

void construir(int p, int izq, int der)
{
	if ( izq == der )
	{
		//printf("estoy hasta abajo %d\n",izq );
		//imprimir(arreglo[izq]);
		//printf("\n");
		segment_tree[p] = arreglo[izq];
		return;
	}
	int pi = hi(p), pd = pi+1, mitad = (izq+der)>>1;
	construir( pi, izq, mitad );
	construir( pd,mitad+1, der );

	//printf("suma estoy en el nodo p %d\n", p);
	//imprimir(segment_tree[ hi(p) ]);
	//imprimir(segment_tree[ hd(p) ]);
	segment_tree[p] = sumar( segment_tree[ pi ], segment_tree[ pd ] );
	//imprimir(segment_tree[ p ]);
	//printf("\n");
}

void propagar(int p, int izq, int der)
{
	if (not necesita_cambio[p]) return;

	segment_tree[p] = igualar( cambio[p], der- izq + 1 );

	if (izq != der )
	{
		int pi = hi(p), pd = pi+1, mitad = (izq+der)>>1;
		necesita_cambio[pi] = necesita_cambio[pd] = true;
		cambio[pi] = cambio[p];
		cambio[pd] = cambio[p];
	}
	necesita_cambio[p] = false;
}

void actualizar(int p, int izq, int der)
{
	propagar( p, izq, der);
	if (i > der or j <izq) return;

	if (izq == der)
	{
		segment_tree[p] = comodin;
		return;
	}

	int pi = hi(p), pd = pi+1, mitad = (izq+der)>>1;
	if (izq >= i and der <= j)
	{
		segment_tree[p] = igualar( comodin, der - izq +1);		
		necesita_cambio[pi] = necesita_cambio[pd] = true;
		cambio[pi] = comodin;
		cambio[pd] = comodin;
		return;		
	}

	actualizar (pi, izq, mitad);
	actualizar (pd, mitad +1, der);

	segment_tree[p] = sumar( segment_tree[ pi ], segment_tree[ pd ] );
	
}

array <int, 10> consulta(int p, int izq, int der)
{
	if (i >der or j <izq) return cero;
	propagar(p, izq, der);
	array <int, 10> res;
	if (izq >= i and der <= j)
	{
		//for (int w = 0; w < 10; ++w)
			//res[w] = segment_tree[p][w];
		//return res;	
		return segment_tree[p];
	}
	int pi = hi(p), pd = pi+1, mitad = (izq+der)>>1;
	array <int, 10> q1 = consulta (pi, izq, mitad),
					q2 = consulta (pd, mitad + 1, der);
	for (int w = 0; w< 10; ++w)
		q1[w] += q2[w];
	return q1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.sync_with_stdio(false);
	int n, k;		
	while(cin>>n>>k){
	for ( i = 0; i < n; ++i)
	{
		cin>>s;
		arreglo[i] = convertir(  );
		//for (int w = 0; w < 10; ++w)
		//	printf("%d: %d\n",w, arreglo[i][w] );
		//printf("\n");
	}
	necesita_cambio.reset();
	construir(1, 0, n-1);
	//for (int i = 0; i < 10; ++i)	
		//printf("%d\n", cero[i]);	


	//printf("\n\n\n\n");
	while (k--)
	{		
		//scanf("%d %d %d", &op, &i, &j);
		cin>>op>>i>>j;
		--i; --j;
		if (op)
		{
			cin>>s;
			comodin = convertir(  );
			actualizar(1, 0, n-1);
		}
		else 
		{
			//int arr[10] = consulta(1, 0, n-1);
			array <int, 10> res = consulta(1, 0, n-1);
			int ind=0;
			for (int w = 1; w < 10; ++w)
				//printf("%d: %d\n",w, res[w] );
				if ( res[w]>res[ind] ) ind = w;
			//cout<<ind<<"\n";
			printf("%d\n",ind );
			//printf("\n");
		}

	}}	
	
	return 0;
}