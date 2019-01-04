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
//#define y first
//#define x second.first
//#define z second.second
using namespace std;
typedef pair <int, int> ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef long long ll;
//typedef pair <int, ii > coor;
struct coor
{ int y, x, z, pasos; };


//char matriz[110][110][110];
string matriz[110][110];

int r, c, a;
coor find(char cha)
{
	int i, j, k;
	for (i=0; i<r; ++i)
		for (j=0; j<c; ++j)
			for (k=0; k<a; ++k)
				if (matriz[k][i][j]==cha)
				{
					matriz[k][i][j]='.';
					coor pos{i,j,k, 0};
					return pos;	
				}
}
//bool posible;
void imprime();
int arrx[]={1,-1,0,0,0,0}, arry[]={0,0,1,-1,0,0}, arrz[]={0,0,0,0,1,-1 };
int busca()
{
	coor posS, posE;
	posS=find('S');
	posE=find('E');
	int vuelta=0;
	queue <coor> colaS, colaE;

		//posible=false;
	colaS.push(posS); colaE.push(posE);
	int x, y, z, pasos, i, xs, ys, zs;
	char p;

	while (!colaS.empty() and !colaE.empty())
	{
		while (!colaS.empty() and colaS.front().pasos==vuelta ){
		posS=colaS.front();
		colaS.pop();
		x=posS.x; y=posS.y; z=posS.z; pasos=posS.pasos;
		char &qS=matriz[z][y][x];

		if (qS=='S') continue;
		//if (q=='E')
		//	return pasos;
		for (i=0; i<4; ++i)
		{
			ys=y+arry[i]; xs=x+arrx[i];
			if (  ys<0 or xs<0 or ys==r or xs == c  ) continue;
			p=matriz[ z ][ ys ][ xs ];
			if (p=='E')
			{
				//imprime(); 
				//cout<<"econtre qE"<<endl<<z<<" "<<ys<<" "<<" "<<xs<<endl; 
				return 2*pasos;
			}
			if ( p=='.' or p=='-' )
			{
				colaS.push( coor{ys, xs, z, pasos+1} );
				//matriz[ y+arry[i] ][ x+arrx[i] ][ z+arrz[i] ]='#';
			}
		}
		for (; i<6; ++i)
		{
			zs=z+arrz[i]; 
			if ( zs<0  or zs==a   ) continue;
			p=matriz[ zs ][ y ][ x ];
			//q=matriz[y][x][z];
			if (p=='-' and qS=='-')
			{
				colaS.push( coor{y, x, zs, pasos+1} );
				//matriz[ y+arry[i] ][ x+arrx[i] ][ z+arrz[i] ]='#';
			}
		}
		qS='S';

		}

		while (!colaE.empty() and colaE.front().pasos==vuelta)
		{
		posE=colaE.front();
		colaE.pop();
		x=posE.x; y=posE.y; z=posE.z; pasos=posE.pasos;
		char &qE=matriz[z][y][x];
		if (qE=='E') continue;
		//if (q=='E')
		//	return pasos;
		for (i=0; i<4; ++i)
		{
			ys=y+arry[i]; xs=x+arrx[i];
			if (  ys<0 or xs<0 or ys==r or xs == c  ) continue;
			p=matriz[ z ][ ys ][ xs ];
			if (p=='S') 
			{ 
				//imprime(); 
				//cout<<"econtre S"<<endl<<z<<" "<<ys<<" "<<" "<<xs<<endl; 
				return 2*pasos+1;
			}
			if ( p=='.' or p=='-' )
			{
				colaE.push( coor{ys, xs, z, pasos+1} );
				//matriz[ y+arry[i] ][ x+arrx[i] ][ z+arrz[i] ]='#';
			}
		}
		for (; i<6; ++i)
		{
			zs=z+arrz[i]; 
			if ( zs<0  or zs==a   ) continue;
			p=matriz[ zs ][ y ][ x ];
			//q=matriz[y][x][z];
			if (p=='-' and qE=='-')
			{
				colaE.push( coor{y, x, zs, pasos+1} );
				//matriz[ y+arry[i] ][ x+arrx[i] ][ z+arrz[i] ]='#';
			}
		}
		qE='E';

		}
		//cout<<"vuelta "<<vuelta++<<"\n";
		//imprime();
		vuelta++;
	}
	return -1;
}

void imprime()
{
	int i,j,k;
	for (k=0; k<a; ++k, cout<<endl<<endl)
			for (i=0; i<r; ++i, cout<<endl)
				for (j=0; j<c; ++j)
					{
						//if(matriz[i][j][k]=='E')
							//cout<<' ';
						//else 
						printf("%c", matriz[k][i][j]);
					}
}

int main()
{
	int i, j, k, res;
	char ve;
	string ss;
	while (scanf("%d %d %d", &r, &c, &a) and r  )
	{
		//scanf("%c",&ve);
		getline(cin, ss);
		for (k=0; k<a; ++k, getline(cin, ss))
			for (i=0; i<r; ++i)
				//scanf("%s", matriz[k][i]);
				getline(cin, matriz[k][i]);
		/*
		for (k=1; k<=a; ++k, scanf("%c",&ve))
			for (i=1; i<=r; ++i)
				for (j=1; j<=c+1; ++j)
					scanf("%c",&matriz[k][i][j]);

				*/


		//for (i=0; i<=r+1; ++i)
		//	for (j=0; j<=c+1; ++j)
		//		matriz[i][j][0]=matriz[i][j][a+1]='#';

		//for (i=0; i<=r+1; ++i)
		//	for (k=0; k<=a+1; ++k)	
		//		matriz[i][c+1][k]=matriz[i][0][k]='#';
		
		//for (j=0; j<=c+1; ++j)
		//	for (k=0; k<=a+1; ++k)	
		//			matriz[r+1][j][k]=matriz[0][j][k]='#';
		
		
		//getline(cin, ss);
		//
		//imprime();
		//while (!cola.empty()) cola.pop();
		
		res=busca();
		printf("%d\n", res);
		//imprime();
	}
	return 0;
}