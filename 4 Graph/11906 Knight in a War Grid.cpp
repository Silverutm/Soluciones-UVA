#include <bits/stdc++.h>
#define tam 105
using namespace std;
int tablero[tam][tam];
int arr[5], r, c, impares, pares, n, m;

bool dentro(int a, int z)
{
	return a>=0 and a<z;
}

void buscar(int y,int x)
{
	tablero[y][x] = 1;

	int vecinos = 0, yt, xt;
	int a, b;
	if (arr[0]==arr[1]) a=1;
	else a=2;
	if (arr[2]==arr[3]) b=1;
	else b=2;
	for (int i = 0; i < 0+a; ++i)
		for (int j = 2; j < 2+b; ++j)
		{
			yt = y + arr[i]; xt = x + arr[j];
			if ( dentro( yt , r ) and dentro( xt , c ) and 
				  tablero[yt][xt]!=-1  )
			{
				++vecinos;
				if ( tablero[yt][xt]==0 )
					buscar(yt, xt);
			}
		}

	/*if (arr[0]==arr[1]) a=1;
	else a=2;
	if (arr[2]==arr[3]) b=1;
	else b=2;*/
	if ( m!=n)
	for (int i = 2; i < 2+b; ++i)
		for (int j = 0; j < 0+a; ++j)
		{
			yt = y + arr[i]; xt = x + arr[j];
			if ( dentro( yt , r ) and dentro( xt , c ) and 
				  tablero[yt][xt]!=-1  )
			{
				++vecinos;
				if ( tablero[yt][xt]==0 )
					buscar(yt, xt);
			}
		}
	//if (vecinos)
	//{
		if (vecinos&1)
			++impares;
		else ++pares;
	//}
}

int main()
{
	int x, y, t, w;
	cin>>t;
	for (int caso = 1; caso <= t; ++caso)
	{
		memset(tablero, 0, sizeof tablero);

		cin>>r>>c>>n>>m>>w;
		while (w--)
		{
			cin>>y>>x;
			tablero[y][x] = -1;
		}
		arr[0] =m;arr[1]=-m;  arr[2]=n;arr[3]=-n;
		impares = pares = 0;
		buscar(0,0);

		cout<<"Case "<<caso<<": "<<pares<<" "<<impares<<"\n";

		/*for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				int x =tablero[i][j];
				if(x==0) cout<<".";
				else if (x==-1) cout<<"x";
				else cout<<"*";

			}
			cout<<endl;
		}
		cout<<endl;*/
	}
	return 0;
}