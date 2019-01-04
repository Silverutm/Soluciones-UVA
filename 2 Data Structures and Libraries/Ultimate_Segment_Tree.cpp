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
int mov;
int convertir(char c)
{
	if (c=='F') return S;
	if (c=='E') return C;
	if (c=='I') return F;
	return N;
}

int cuantos(int mov,int izq, int der, int p)
{
	if (mov == C) return 0;
	if ( mov == S ) return der -izq + 1;
	if ( mov ==F ) return der -izq + 1 - segment_tree[p];
	return segment_tree[p];
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

int cambio(int a, int b)
{
	if ( a!= F ) return a;
	if (b == F) return N;
	if (b == C) return S;
	if (b== S) return C;
	if ( b==N ) return F;
}

void propagar(int p, int izq, int der)
{
	if ( necesito_cambio[p] == N ) return;

	//if ( necesito_cambio[p] == F )

	segment_tree[p] = cuantos( necesito_cambio[p] ,izq, der, p );

	if (izq != der)
	{
		necesito_cambio[hijo_derecho(p)] = cambio( necesito_cambio[p], necesito_cambio[hijo_derecho(p)]);
		necesito_cambio[hijo_izquierdo(p)] = cambio( necesito_cambio[p], necesito_cambio[hijo_izquierdo(p)]);
	}
	necesito_cambio[p] = N;
}

void arbol_actualizar(int p, int izq, int der)
{
	propagar(p, izq, der);
	if ( i > der or j < izq ) return;
	if ( izq == der )
	{
		segment_tree[p] = cuantos(mov,izq, der, p);
		return;
	}
	if ( izq >= i and der <= j )
	{
		segment_tree[p] = cuantos(mov,izq, der, p);
		necesito_cambio[ hijo_izquierdo(p) ] = cambio( mov, necesito_cambio[hijo_izquierdo(p)]);
		necesito_cambio[ hijo_derecho(p) ] = cambio( mov, necesito_cambio[hijo_derecho(p)]);
		return ;
	}
	arbol_actualizar( hijo_izquierdo(p), izq, (izq+der)/2 );
	arbol_actualizar( hijo_derecho(p), (izq+der)/2 + 1, der );

	segment_tree[p] = segment_tree[hijo_izquierdo(p)] + segment_tree[hijo_derecho(p)];
}

int rmq(int p, int izq, int der)
{
	if ( i > der or j < izq ) return 0;	
	propagar(p, izq, der);
	if ( izq >= i and der <= j ) return segment_tree[p];

	int q1 = rmq(hijo_izquierdo(p) , izq, (izq + der)/2),
		q2 = rmq(hijo_derecho(p) ,(izq + der)/2 + 1, der);
	
	return q1 + q2;
}

int main()
{
	int n, q, a, t, p, pregunta;	
	string s;
	char c;
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
		
		for ( i = 0; i < 4*n; ++i)
			necesito_cambio[i] = segment_tree[i] = 0;

		construir(1, 0, n - 1);
		
		cout<<"Case "<<caso<<":\n";
		cin>>q;
		while (q--)
		{
			cin>>c>>i>>j;
			mov = convertir( c );
			if ( mov!=N ) arbol_actualizar(1, 0 , n-1);
			else cout<<"Q"<<++pregunta<<": "<<rmq(1,0, n-1)<<"\n";
			//if (c == 'S') cout<<"Q"<<++pregunta<<": "<<respuesta<<"\n";
			
		}
	}
	return 0;
}





#include <iostream>

#define mod 1000000007
#define tam 100003
using namespace std;
typedef long long ll;

ll fact[100005], factreverso[100005];

ll n_en_k(int n, int k)
{
	if (n<k) return 0LL;
	ll res= fact[n];
	res = res*factreverso[k]%mod;
	res = res*factreverso[n-k]%mod;
	return res;
}


ll fastpow( ll a, ll n )
{
	ll res=1;
	while ( n )
	{
		if ( n&1 )
			res=res*a%mod;
		a = a*a%mod;
		n >>=1;
	}
	return res;
}


int main()
{
	int n, k, res;
	fact[0]=1;
	for (int i=1; i<= tam; ++i)
		fact[i] = fact[i-1] * i % mod;

	factreverso[tam]=fastpow( fact[tam] , mod-2);
	//for (int i=0; i<= tam; ++i)
		//factreverso[i]=fp;

	for (int i=tam-1; i>=0; --i)
		factreverso[i] = factreverso[i+1]*(i+1)%mod;

	while (cin>>n>>k)
	{
		res=n_en_k(n-1, k)%mod;
		res <<=1;
		res %=mod;
		cout<<res<<endl;
	}
	return 0;
}




ll gcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll r = gcd(b, a%b, y, x);
	y -= a/b*x;
	return r;
}


inline ll restmod(const ll &a, const ll &b, const ll &m)
{
	return ( ( (a % m) - (b % m) ) + m ) % m;
}

inline ll divmod(const ll &a, const ll &b, const ll &m)
{
	ll binv;
	ll y;
	gcd(b, m, binv, y);

	binv = ((binv%m)+m)%m;

	return ( (a % m) * (binv % m) ) % m;
}


n-ésimo término de Fibonacci:
[((1+sqrt(5))/2)^n + ((1-sqrt(5))/2)^n] / sqrt(5)

int lastNon0Digit(int n)
{
     if (n < 10)
        return dig[n];
 
    // Check whether tens (or second last) digit
    // is odd or even
    // If n = 375, So n/10 = 37 and (n/10)%10 = 7
    // Applying formula for even and odd cases.
    if (((n/10)%10)%2 == 0)
        return (6*lastNon0Digit(n/5)*dig[n%10]) % 10;
    else
        return (4*lastNon0Digit(n/5)*dig[n%10]) % 10;
}