#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#define pb push_back
#define mk make_pair
#define f first
#define s second
using namespace std;
typedef pair <int, int> ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef long long ll;

struct coor
{ int y, x, z, pasos; };

char matriz[110][110][110];

int r, c, a;
coor find()
{
	int i, j, k;
	for (i=1; i<=r; ++i)
		for (j=1; j<=c; ++j)
			for (k=1; k<=a; ++k)
				if (matriz[i][j][k]=='S')
				{
					matriz[i][j][k]='.';
					coor pos{i,j,k, 0};
					return pos;	
				}
}
//bool posible;
queue <coor> cola;
int arrx[]={1,-1,0,0,0,0}, arry[]={0,0,1,-1,0,0}, arrz[]={0,0,0,0,1,-1 };
int busca()
{
	coor pos;
	int x, y, z, pasos, i;
	char p, q;
	while (!cola.empty())
	{
		pos=cola.front();
		cola.pop();
		x=pos.x; y=pos.y; z=pos.z; pasos=pos.pasos;
		q=matriz[y][x][z];
		if (q=='E')
			return pasos;
		for (i=0; i<4; ++i)
		{
			p=matriz[ y+arry[i] ][ x+arrx[i] ][ z+arrz[i] ];
			if ( p=='.' or p=='-'  or p=='E')
			{
				cola.push( coor{y+arry[i], x+arrx[i], z+arrz[i], pasos+1} );
				//matriz[ y+arry[i] ][ x+arrx[i] ][ z+arrz[i] ]='#';
			}
		}
		for (; i<6; ++i)
		{
			p=matriz[ y+arry[i] ][ x+arrx[i] ][ z+arrz[i] ];
			//q=matriz[y][x][z];
			if (p=='-' and q=='-')
			{
				cola.push( coor{y+arry[i], x+arrx[i], z+arrz[i], pasos+1} );
				//matriz[ y+arry[i] ][ x+arrx[i] ][ z+arrz[i] ]='#';
			}
		}
		matriz[y][x][z]='#';
	}
	return -1;
}

void imprime()
{
	int i,j,k;
	for (k=1; k<=a; ++k, cout<<endl<<endl)
			for (i=1; i<=r; ++i, cout<<endl)
				for (j=1; j<=c; ++j)
					{
						//if(matriz[i][j][k]=='E')
							//cout<<' ';
						//else 
						cout<<matriz[i][j][k];
					}
}

int main()
{
	int i, j, k, res;
	while (cin>>r>>c>>a and ( r or c or a ) )
	{
		for (i=0; i<=r+1; ++i)
			for (j=0; j<=c+1; ++j)
				matriz[i][j][0]=matriz[i][j][a+1]='#';

		for (i=0; i<=r+1; ++i)
			for (k=0; k<=a+1; ++k)	
				matriz[i][c+1][k]=matriz[i][0][k]='#';
		
		for (j=0; j<=c+1; ++j)
			for (k=0; k<=a+1; ++k)	
					matriz[r+1][j][k]=matriz[0][j][k]='#';
		
		for (k=1; k<=a; ++k)
			for (i=1; i<=r; ++i)
				for (j=1; j<=c; ++j)
					cin>>matriz[i][j][k];

		//imprime();
		while (!cola.empty()) cola.pop();
		coor pos=find();
		//posible=false;
		cola.push(pos);
		res=busca();
		printf("%d\n", res);
		//imprime();
	}
	return 0;
}