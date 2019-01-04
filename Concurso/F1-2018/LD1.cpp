#include <stdio.h>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#define pb push_back
#define MAXN 1000000
using namespace std;
typedef long long ll;
typedef pair < ll, int > pare;

struct ura
{
	int x, y;
	bool operator < ( const ura &A ) const
	{
		return ( x < A.x );
	}
} arr[ MAXN ];
int alt[ MAXN ];
int X, Y, N;
map < pair < ura, short >, vector < pare > > mapa;

int __gcd( int a, int b )
{
	if( a < b )
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
	return ( a % b == 0 ? b : __gcd( b, a % b ) );
}

int abs( int x )
{
	return ( x < 0 ? -x : x );
}

void simplificar( ura* p )
{
	if( p -> x == 0 || p -> y == 0 )
	{
		p -> x = p -> y = 0;
		return;
	}
	int gcd = __gcd( abs( p -> x ), abs( p -> y ) );
	p -> x /= gcd;
	p -> y /= gcd;
	if( p -> x < 0 && p -> y )
	{
		p -> x *= -1;
		p -> y *= -1;
	}
}

short cuadrante( int i )
{
	if( X == arr[ i ].x )	
		return ( arr[ i ].y > Y ? 1 : 2 );
	if( arr[ i ].x < X )
		return ( arr[ i ].y > Y ? 5 : 6 );
	return ( arr[ i ].y < Y ? 4 : 3 );
}

ll sq( ll x )
{
	return x*x;
}

ll dista( ura p )
{
	return sq( p.x ) + sq( p.y );
}

void createList()
{
	ura pendi;
	pair < ura, short > p1;
	pare p2;
	
	for( int i = 0; i < N; i++ )
	{
		// pendiente de la iguana a la TV
		pendi.x = X - arr[ i ].x;
		pendi.y = Y - arr[ i ].y;
		// distancia hacia la TV
		p2.first = dista( pendi );
		// se decide el cuadrante al que pertenece
		p1.second = cuadrante( i );
		// se simplifica la pendiente para que sean iguales
		simplificar( &pendi );
		p1.first = pendi;
		p2.second = alt[ i ];
		mapa[ p1 ].pb( p2 );
	}
}

void read()
{
	scanf( "%d %d", &X, &Y );
	scanf( "%d", &N );
	for( int i = 0; i < N; i++ )
		scanf( "%d %d %d", &arr[ i ].x, &arr[ i ].y, alt + i );
}

bool fsort( pare a, pare b )
{
	return ( a.first < b.first );
}

void sortList()
{
	for( auto c: mapa )
		sort( c.second.begin(), c.second.end(), fsort );
}

main()
{
	read();
	createList();
	sortList();
	
	pare p2;
	for( auto c: mapa )
	{
		for( int i = 0; i < c.second.size(); i++ )
		{
			p2 = c.second[ i ];
			printf( "%lld %d\n", p2.first, p2.second );
		}
		printf( "\n" );
	}
}
