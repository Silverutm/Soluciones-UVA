#include <bits/stdc++.h>
using namespace std;

struct punto
{
	int x, y;	
};
punto arr[ 20000 ][ 2 ];

int ori( punto a, punto b, punto c )
{
	int x = ( c.x-b.x )*( b.y-a.y ) - ( c.y-b.y )*( b.x-a.x );
	if( x > 0 ) return 1;
	if( x < 0 ) return -1;
	return 0;
}

bool dentro( punto a, punto b, punto c )
{
	if( min( a.x, b.x ) <= c.x && c.x <= max( a.x, b.x ) )
		if( min( a.y, b.y ) <= c.y && c.y <= max( a.y, b.y ) )
			return true;
	return false;
}

bool chocan( int a, int b )
{
	int o1 = ori( arr[ a ][ 0 ], arr[ a ][ 1 ], arr[ b ][ 0 ] );
	int o2 = ori( arr[ a ][ 0 ], arr[ a ][ 1 ], arr[ b ][ 1 ] );
	int o3 = ori( arr[ b ][ 0 ], arr[ b ][ 1 ], arr[ a ][ 0 ] );
	int o4 = ori( arr[ b ][ 0 ], arr[ b ][ 1 ], arr[ a ][ 1 ] );
	if( o1 != o2 && o3 != o4 )
		return true;
	if( o1 == 0 && dentro( arr[ a ][ 0 ], arr[ a ][ 1 ], arr[ b ][ 0 ] ) )
		return true;
	if( o2 == 0 && dentro( arr[ a ][ 0 ], arr[ a ][ 1 ], arr[ b ][ 1 ] ) )
		return true;
	if( o3 == 0 && dentro( arr[ b ][ 0 ], arr[ b ][ 1 ], arr[ a ][ 0 ] ) )
		return true;
	if( o4 == 0 && dentro( arr[ b ][ 0 ], arr[ b ][ 1 ], arr[ a ][ 1 ] ) )
		return true;			
	return false;
}

int intersecciones( int x )
{
	int total = 0;
	for( int i = 0; i < x; i++ )
		if( chocan( i, x ) )
			total++;
	return total+total;
}

main()
{
	bool bandera = false;
	int T, N, total;
	scanf( "%d", &T );
	while( T-- )
	{
		scanf( "%d", &N );
		total = N;
		for( int i = 0; i < N; i++ )
		{
			scanf( "%d %d", &arr[ i ][ 0 ].x, &arr[ i ][ 0 ].y );
			scanf( "%d %d", &arr[ i ][ 1 ].x, &arr[ i ][ 1 ].y );
			total += intersecciones( i );
			//printf("%d: %d\n", i, total );
		}
		if( bandera )
			printf( "\n" );
		bandera = true;
		printf( "%d\n", total );
	}
}