#include <iostream>
#include <cstdio>
using namespace std;

bool pieza[10][10], tablero[30][30], temp[10][10];

int xp,yp, xt, yt;

bool revisa()
{
	int i, j, k, l, x, y;
	bool chido=false;
	for ( i=1; i<=yt and !chido ; ++i )
		for (j=1; j<=xt and !chido ; ++j)
		{
			chido=true;
			for (k=1; k <= yp and chido; ++k )
				for ( l=1; l<=xp and chido; ++l)
				{
					y=i+k-1;
					x=j+l-1;
					if (x>xt or y>yt)
					{
						chido=false;
						continue;
					}
					if (  tablero[y][x] and pieza[k][l]   )
						chido=false;
				}
		}
	return chido;
}

void voltea()
{
	int i, j;
	for ( i=1; i<=yp; ++i)
		for ( j=1; j<=xp; ++j)
			temp[i][xp-j+1]=pieza[i][j];
	
	for ( i=1; i<=yp; ++i)
		for ( j=1; j<=xp; ++j)
			pieza[i][j]=temp[i][j];
}

void gira()
{
	int x=xp, y=yp, i ,j;
	for ( j=1; j<=xp; ++j)
		for ( i=yp; i>=1; --i)
			temp[j][yp-i+1]=pieza[i][j];
	yp=x; xp=y;
	for ( i=1; i<=yp; ++i)
		for ( j=1; j<=xp; ++j)
			pieza[i][j]=temp[i][j];
}


void imprime()
{
	return ;
	int i, j;
	for (i=1; i<=yp; ++i,cout <<endl)
		for (j=1; j<=xp; ++j)
			cout<<pieza[i][j];
	cout<<endl;
}

bool renglonceros(int i)
{
	bool po=true;
	int j;
	for (j=1; j<=xp and po;++j)
		if (pieza[i][j]==true) po=false;
	return po;
}

bool colglonceros(int j)
{
	bool po=true;
	int i;
	for (i=1; i<=yp and po;++i)
		if (pieza[i][j]==true) po=false;
	return po;
}
void recorta()
{
	int iniy=1, finy=yp, inix=1, finx=xp;
	while (renglonceros(iniy)) ++iniy;
	while (renglonceros(finy)) --finy;

	while (colglonceros(inix)) ++inix;
	while (colglonceros(finx)) --finx;
	int i, j;
	for ( i=iniy; i<=finy; ++i)
		for ( j=inix; j<=finx; ++j)
			temp[i-iniy+1][j-inix+1]=pieza[i][j];
	for (i=1; i<=finy-iniy+1; ++i)
		for (j=1; j<=finx-inix+1; ++j)
			pieza[i][j]=temp[i][j];
	xp=finx-inix+1;
	yp=finy-iniy+1;
}

int main()
{
	int i, j;
	bool posible;
	while (cin>>xp>>yp)
	{
		for (i=1; i<=yp; ++i)
			for (j=1; j<=xp; ++j)
				cin>>pieza[i][j];
		recorta();
		imprime();
		cin>>yt>>xt;
		for (i=1; i<=yt; ++i)
			for (j=1; j<=xt; ++j)
				cin>>tablero[i][j];
		posible=false;

		for (i=1; i<=4; ++i)
		{
			posible= posible or revisa();			
			gira();			
		}

		voltea();
		for (i=1; i<=4; ++i)
		{
			posible= posible or revisa();
			gira();
		}
		if (posible) printf("YES");
		else printf("IMPOSSIBLE");
	}
	return 0;
}