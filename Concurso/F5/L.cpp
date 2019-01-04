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

string matriz[110][110];

int r, c, a;
coor find()
{
	int i, j, k;
	for (i=1; i<=r; ++i)
		for (j=0; j<c; ++j)
			for (k=1; k<=a; ++k)
				if (matriz[k][i][j]=='S')
				{
					matriz[k][i][j]='.';
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
		q=matriz[z][y][x];
		if (q=='E')
			return pasos;
		for (i=0; i<4; ++i)
		{
			if (x+arrx[i]<0 or x+arrx[i]>=c) continue;
			p=matriz[ z+arrz[i] ][ y+arry[i] ][ x+arrx[i] ];
			if ( p=='.' or p=='-'  or p=='E')
			{
				cola.push( coor{y+arry[i], x+arrx[i], z+arrz[i], pasos+1} );
				//matriz[ y+arry[i] ][ x+arrx[i] ][ z+arrz[i] ]='#';
			}
		}
		for (; i<6; ++i)
		{
			if (x+arrx[i]<0 or x+arrx[i]>=c) continue;
			p=matriz[ z+arrz[i] ][ y+arry[i] ][ x+arrx[i] ];
			//q=matriz[y][x][z];
			if (p=='-' and q=='-')
			{
				cola.push( coor{y+arry[i], x+arrx[i], z+arrz[i], pasos+1} );
				//matriz[ y+arry[i] ][ x+arrx[i] ][ z+arrz[i] ]='#';
			}
		}
		matriz[z][y][x]='#';
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
						cout<<matriz[k][i][j];
					}
}

int main()
{
	int i, j, k, res;
	while (cin>>r>>c>>a and ( r or c or a ) )
	{
		//cout<<r<<c<<a<<endl;
		//getchar();
		string ss;
		getline(cin, ss);
		//getline(cin, ss);
		//cout<<ss;
		for (k=1; k<=a; ++k, getline(cin, ss) )
			for (i=1; i<=r; ++i)
				getline(cin, matriz[k][i]);
				//for (j=1; j<=c; ++j)
					//cin>>matriz[k][i][j];
					//scanf("%c", &matriz[i][j][k]);


		for (i=0; i<=r+1; ++i)
			for (j=0; j<c; ++j)
				matriz[0][i][j]=matriz[a+1][i][j]='#';

		//for (i=0; i<=r+1; ++i)
			//for (k=0; k<=a+1; ++k)	
				//matriz[k][i][c]='#';
		
		for (j=0; j<c; ++j)
			for (k=0; k<=a+1; ++k)	
					matriz[k][r+1][j]=matriz[k][0][j]='#';


		//getline(cin, ss);
		//cout<<ss;
					//cin>>matriz[i][j][k];
		//for (k=1; k<=a; ++k)
			//for (i=1; i<=r; ++i)
				//getline(cin, matriz[])
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