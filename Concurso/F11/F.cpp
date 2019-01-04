#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define tam 10005
int izq[tam], icent[tam], der[tam], dcent[tam];
int maxic, maxdc, maxdd, maxii;

void buscaizq(int v, int cant, bool hc)
{
	if  ( icent[v] )
		buscaizq( icent[v], cant + 1 , hc);
	else
	{
		if (hc) maxic = max (maxic, cant);
		else maxii = max( maxii, cant);
	}

	if ( izq[v] )
		buscaizq(izq[v], 1, false);
}

void buscader(int v, int cant, bool hc)
{
	if  ( dcent[v] )
		buscader( dcent[v], cant + 1 , hc);
	else
	{
		if (hc) maxdc = max (maxdc, cant);
		else maxdd = max( maxdd, cant);
	}

	if ( der[v] )
		buscader(der[v], 1, false);
}

int main()
{
	int n, v, m, resta;
	while ( scanf("%d", &n)==1 )
	{
		maxic = maxdc = maxii = maxdd = 0;
		memset(izq, 0, sizeof izq);
		memset(der, 0, sizeof der);
		memset(dcent, 0, sizeof dcent);
		memset(icent, 0, sizeof icent);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &v);
			scanf("%d %d", &izq[v], &icent[v]);
		}

		scanf("%d", &m);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", &v);
			scanf("%d %d", &dcent[v], &der[v]);
		}

		buscaizq(1, 1, true);
		buscader(1, 1, true);
		resta = 0;
		resta = max(  min( maxdc, maxic ),  
					max (  min( maxic, maxdd ), min(maxii, maxdc) )
					 );
		printf("%d\n", n + m - resta );
	}


	return 0;
}