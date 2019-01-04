#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#include <bitset>
#define pb push_back
#define mk make_pair
#define f first
#define s second
using namespace std;
typedef pair <int, int> ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef long long ll;
int tablero[30][30], raiz[30];
bool posible;
bitset <30> ocupados;
int main()
{
	raiz[1]=1;
	raiz[4]=2;
	raiz[9]=3;
	raiz[16]=4;
	raiz[25]=5;
	int t, n, i, j, k, l, p,r;
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (i=1;i<=n; ++i )
			for (j=1;j<=n; ++j )
				cin>>tablero[i][j];
		posible=true;
		for (i=1;i<=n and posible; ++i )
		{
			ocupados.reset();
			for (j=1;j<=n and posible; ++j )
			{
				p=tablero[i][j];
				if (ocupados[p]) posible=false;
				else ocupados[p]=true;
			}
		}

		for (j=1;j<=n and posible; ++j )
		{
			ocupados.reset();
			for (i=1;i<=n and posible; ++i )
			{
				p=tablero[i][j];
				if (ocupados[p]) posible=false;
				else ocupados[p]=true;
			}
		}
		r=raiz[n];
		for (i=1;i<=n and posible; i+=r )
			for (j=1;j<=n and posible; j+=r )
			{
				ocupados.reset();
				for (k=i; k<=i+r-1 and posible; ++k)
					for (l=j; l<=j+r-1 and posible; ++l)
					{
						p=tablero[k][l];
						if (ocupados[p]) posible=false;
						else ocupados[p]=true;
					}
			}

		if (posible ) cout<<"yes\n";
		else cout<<"no\n";

	}
	return 0;
}