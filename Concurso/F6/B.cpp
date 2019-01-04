#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <queue>

#define pb push_back
#define k first
#define d second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair < int,int > ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < vi > vvi;
#define arriba 0
#define abajo 1
#define izquierda 2
#define derecha 3
#define atras 4
#define adelante 5
struct cort
{
	int y,x, t, v;
};
queue < cort > cola;
int ini=50;
int matriz[500][500][10];

void buscar()
{
	cort c{ini,ini,0, arriba};
	cola.push(c);
	int v;
	while (cola.front().t< ini )
	{
		c=cola.front(); cola.pop();
		if ( matriz[c.y][c.x][c.v]!=-1 )
			continue;
		matriz[c.y][c.x][c.v]=c.t;
		v=c.v;
		if (v==arriba)
		{
			cola.push( cort{c.y-1, c.x, c.t+1,adelante } );
			cola.push( cort{c.y+1, c.x, c.t+1, atras} );
			cola.push( cort{c.y, c.x-1, c.t+1, izquierda} );
			cola.push( cort{c.y, c.x+1, c.t+1, derecha} );
		}
		else if (v==abajo)
		{
			cola.push( cort{c.y-1, c.x, c.t+1, atras} );
			cola.push( cort{c.y+1, c.x, c.t+1, adelante} );
			cola.push( cort{c.y, c.x-1, c.t+1, derecha} );
			cola.push( cort{c.y, c.x+1, c.t+1, izquierda} );
		}
		else if (v==adelante)
		{
			cola.push( cort{c.y-1, c.x, c.t+1,abajo } );
			cola.push( cort{c.y+1, c.x, c.t+1, arriba} );
			cola.push( cort{c.y, c.x-1, c.t+1, adelante} );
			cola.push( cort{c.y, c.x+1, c.t+1, adelante} );
		}
		else if (v==atras)
		{
			cola.push( cort{c.y-1, c.x, c.t+1,arriba } );
			cola.push( cort{c.y+1, c.x, c.t+1, abajo} );
			cola.push( cort{c.y, c.x-1, c.t+1, atras} );
			cola.push( cort{c.y, c.x+1, c.t+1, atras} );
		}
		else if (v==izquierda)
		{
			cola.push( cort{c.y-1, c.x, c.t+1, izquierda} );
			cola.push( cort{c.y+1, c.x, c.t+1, izquierda} );
			cola.push( cort{c.y, c.x-1, c.t+1, abajo} );
			cola.push( cort{c.y, c.x+1, c.t+1, arriba} );
		}
		else if (v==derecha)
		{
			cola.push( cort{c.y-1, c.x, c.t+1, derecha} );
			cola.push( cort{c.y+1, c.x, c.t+1, derecha} );
			cola.push( cort{c.y, c.x-1, c.t+1, arriba} );
			cola.push( cort{c.y, c.x+1, c.t+1, abajo} );
		}
	}
}

int main()
{
	cin>>ini;
	memset(matriz, -1, sizeof matriz);
	buscar();
	//for (int i=0; i<2*ini; ++i, printf("\n"))
	//	for (int j=0; j<2*ini; ++j)
	//		printf("%3d",matriz[i][j][arriba] );
	for (int i=0; i<=ini; ++i, printf("\n"))
		for (int j=1; j<=i+1; ++j)
			printf("%3d",matriz[i][ini+j-1][arriba] );
	return 0;
}