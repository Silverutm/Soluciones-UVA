#include <iostream>
#include <bitset>
#define N 0
#define S 1
#define F 2
#define C 3

using namespace std;
#define tam 1024009
int segment_tree[tam*4],i, j, necesito_cambio[tam*4];
bitset <tam> arreglo;
char c;

int convertir(char c)
{
	if (c=='F') return S;
	if (c=='E') return C;
	if (c=='I') return F;
	return N;
}

int hijo_izquierdo(int p)
{ return p << 1; }

int hijo_derecho(int p)
{ return (p<<1) + 1; }

void construir(int p, int izq, int der)
{
	if (izq == der)
		segment_tree[p] = arreglo[izq];
	else 
	{
		construir( hijo_izquierdo(p), izq, (izq+der)/2 );
		construir( hijo_derecho(p), (izq+der)/2+1, der );
		
		int p1 = segment_tree[ hijo_izquierdo(p) ], 
			p2 = segment_tree[ hijo_derecho(p) ];

		segment_tree[p] = p1 + p2;
	}
}

int rmqOOOOOOOOOOOOOO( int p, int izq, int der )
{
	if (i > der or j<izq) return -1;	//nos salimos del rango
	if (izq >= i and der <= j) return segment_tree[p];	//estamos completamente
													//dentro del rango

	int p1 = rmqOOOOOOOOOOOOOO(hijo_izquierdo(p), izq, (izq+der)/2),
		p2 = rmqOOOOOOOOOOOOOO(hijo_derecho(p), (izq+der)/2+1, der);

	if (p1 == -1) return p2;
	if (p2 == -1 ) return p1;

	return p1 + p2;
}

int cuantos(int izq, int der, int x, int p)
{
	if (x==S)
		return der - izq + 1;
	if (x==C) return 0;
	if (x==F) return der - izq + 1 - segment_tree[p];
	return segment_tree[p];
}

int respuesta;
int rmq( int p, int izq, int der )
{
	int x = necesito_cambio[p], instruccion = convertir(c);
	if (i > der or j < izq) 
		return segment_tree[p];
	//nos salimos del rango
	//if (izq >= i and der <= j) //return segment_tree[p];	//estamos completamente
													//dentro del rango

	
	if ( izq == der )
	{
		segment_tree[p] = cuantos(izq, der, x, p);	
		respuesta += segment_tree[p];
		return segment_tree[p];
	}

	if (izq >= i and der <= j)
	{
		//cout<<"Bueno aqui estoy\n";
		//if (c!='S') necesito_cambio[p] 
		
			//cout<<"Estoy aqui___\n";
		if (instruccion!=F)
		{
			necesito_cambio[hijo_izquierdo(p)] = instruccion;
			necesito_cambio[hijo_derecho(p)] = instruccion;
			necesito_cambio[p] = N;
			segment_tree[p] = cuantos(izq, der, instruccion, p);	
			respuesta += segment_tree[p];
			return segment_tree[p];
		}
		else 
		{
			if ()
		}
		
	}

	int p1 = rmq(hijo_izquierdo(p), izq, (izq+der)/2),
		p2 = rmq(hijo_derecho(p), (izq+der)/2+1, der);

	//if (p1 == -1) return p2;
	//if (p2 == -1 ) return p1;

	return segment_tree[p] = p1 + p2;
}


int actualizar_un_rango(int p, int izq, int der)
{
	if (i > der or j < izq) return segment_tree[p];

	if ( izq == der ) return  segment_tree[p] = arreglo[izq];
	
	//if (izq >= i and der <= j)
	//	segment_tree[p] = arreglo[]
	int p1 = actualizar_un_rango(hijo_izquierdo(p), izq, (izq + der)/2),
		p2 = actualizar_un_rango(hijo_derecho(p), (izq + der)/2 +1, der);

	return segment_tree[p] = p1 + p2;
}

int main()
{
	int n, q, a, t, p, pregunta;	
	string s;
	cin>>t;
	for (int caso = 1; caso <= t; ++caso)	
	{
		arreglo.reset();
		cin>>p;
		i = 0;
		pregunta =0;
		while (p--)
		{
			cin>>a>>s;
			for (int w = 0; w < a; ++w)
				for (auto & e:s)
					arreglo[i++]=e-'0';
		}

		n = i;
		//cout<<n<<"  ene\n";
		//for (int i = 0; i < n; ++i)
		//	cout<<arreglo[i];
		//cout<<endl;
		for ( i = 0; i < 4*n; ++i)
			necesito_cambio[i] = segment_tree[i] = 0;

		construir(1, 0, n - 1);
		
		cout<<"Case "<<caso<<":\n";
		cin>>q;
		while (q--)
		{
			cin>>c>>i>>j;
			respuesta = 0;
			rmq(1,0, n-1);
			if (c == 'S') cout<<"Q"<<++pregunta<<": "<<respuesta<<"\n";
			//else actualizar_un_rango(1, 0, n-1); 
			//for (int w = i; w <= j; ++w)
			//{
			//	if ( c=='F') arreglo[w] = true;
			//	else if (c=='E') arreglo[w] = false;
			//	else if (c=='I') arreglo[w] = not arreglo[w];
				
			//}
			//else cout<<"Q"<<++pregunta<<": "<<rmq(1,0, n-1)<<"\n";

			//cout<<<<"\n";
		}
	}
	return 0;
}