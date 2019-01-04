#include <bits/stdc++.h>
using namespace std;
int n, m,s;
char tablero[105][105];
string instrucciones;
int x, y, dir, cuenta;
bool nofin;

int entrada(char c)
{
	if (c =='N') return 0;
	if (c =='S') return 4;
	if (c =='L') return 2;
	return 6;
}

int main()
{
	while (cin>>n>>m>>s and n)	
	{
		for (int i = 0; i <= m+1; ++i)
			tablero[0][i] = tablero[n+1][i] = '#';

		for (int i = 0; i <= n+1; ++i)
			tablero[i][0] = tablero[i][m+1] = '#';

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)			
				cin>>tablero[i][j];				

		nofin = true;
		for (int i = 1; i <= n and nofin; ++i)
			for (int j = 1; j <= m and nofin; ++j)			
				if(tablero[i][j]!='.' and tablero[i][j]!='#' and tablero[i][j]!='*' )
				{
					y = i;
					x = j;
					dir = entrada(tablero[i][j]);
					nofin=false;
				}

		//cout<<y<<" "<<x<<endl;
		cuenta = 0;
		cin>>instrucciones;
		for (auto &c:instrucciones)
		{
			if (c=='F')
			{
				if ( dir ==0 and tablero[y - 1][x]!='#' )
					--y;
				else if ( dir ==2 and tablero[y][x + 1]!='#' )
					++x;
				else if ( dir ==4  and tablero[y + 1][x]!='#')
					++y;
				else if ( dir ==6 and tablero[y][x - 1]!='#')
					--x;

				if (tablero[y][x] == '*')
				{
					++cuenta;
					tablero[y][x] = '.';
				}
			}
			else if (c=='D')
				dir = (dir+2)%8;
			else dir = (dir+6)%8;
		}
		cout<<cuenta<<"\n";
	}
	return 0;
}