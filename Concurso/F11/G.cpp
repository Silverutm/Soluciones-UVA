#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define tam 505
#define blanco 1
#define negro 2
int n, p;
int entrada[tam][tam], acum_bla[tam][tam], acum_neg[tam][tam];

int es(int a, int color)
{ return a==color; }

int diagonal_neg(int ii, int i, int ji, int j)
{
	return acum_neg[i][j] - acum_neg[ii-1][j] - acum_neg[i][ji-1] + acum_neg[i-1][j-1];
}
int diagonal_bla(int ii, int i, int ji, int j)
{
	return acum_bla[i][j] - acum_bla[ii-1][j] - acum_bla[i][ji-1] + acum_bla[i-1][j-1];
}

int main()
{
	int x, y, i, j, i1, j1, ii, ji, cn, cb, tn, tb;
	while (scanf("%d %d", &n, &p)==2)
	{
		memset(entrada, 0, sizeof entrada);
		tn = 0; tb = 0;
		//entrada
		for ( i = 0; i < p; ++i)
		{
			scanf("%d %d", &x, &y);
			entrada[y][x] = negro;
		}
		for ( i = 0; i < p; ++i)
		{
			scanf("%d %d", &x, &y);
			entrada[y][x] = blanco;
		}

		//acumulada
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= n; ++j)
			{
				acum_neg[i][j] = acum_neg[i][j-1] + acum_neg[i-1][j]
							 - acum_neg[i-1][j-1] + es( entrada[i][j], negro );

				acum_bla[i][j] = acum_bla[i][j-1] + acum_bla[i-1][j]
							 - acum_bla[i-1][j-1] + es( entrada[i][j], blanco );
			}

		for (j1=1; j1<=n; ++j1)
		{
			i = ii = 1;
			j = ji = j1;
			while (j<=n)
			{
				cn = diagonal_neg( ii, i, ji, j );
				cb = diagonal_bla( ii, i, ji, j );
				if ( !cb )
				{
					if ( cn )
						++tn;
					++i; ++j;
				}
				else if ( entrada[i][j]==blanco )
				{
					ii = i+1; ji =j+1;
					++i; ++j;
				}
				else 
				{
					ii = i; ji =  j;
				}				
			}
		}
		for (i1=2; i1<=n; ++i1)
		{
			i = ii = i1;
			j = ji = 1;
			while (i<=n)
			{
				cn = diagonal_neg( ii, i, ji, j );
				cb = diagonal_bla( ii, i, ji, j );
				if ( !cb )
				{
					if ( cn )
						++tn;
					++i; ++j;
				}
				else if ( entrada[i][j]==blanco )
				{
					ii = i+1; ji =j+1;
					++i; ++j;
				}
				else 
				{
					ii = i; ji =  j;
				}				
			}
		}
		printf("%d\n", tn);
	}
	return 0;
}