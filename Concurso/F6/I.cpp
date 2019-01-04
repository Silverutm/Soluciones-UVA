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
#define f first
#define s second
using namespace std;
typedef pair <int, int> ii;
typedef vector < ii > vii;
typedef vector <int> vi;
vii respuesas;
int n;
bool posible;
char solucion[13][13];

void rotar()
{
	for (int i=0; i<respuesas.size(); ++i)
	{
		ii c=respuesas[i];
		respuesas[i].f=c.s;
		respuesas[i].s=n-c.f-1;
	}
}
int raiz[105];
int main()
{
	char a;
	int i, j, k;
	string cadena;
	for (i=0; i<=10; ++i)
		raiz[i*i]=i;
	while (cin>>n)
	{
		respuesas.clear();
		for (i=0; i<n; ++i)
			for (j=0; j<n; ++j)
			{
				cin>>a;
				if (a=='.')
					respuesas.pb(ii{i,j});
			}
		cin>>cadena;
		posible=true;
		//if (respuesas.size())
		//{
		//	if (cadena.size()%respuesas.size()) posible=false;
		//}
		//else posible=false;
		k=0;
		memset(solucion, 0, sizeof solucion);
		if (not respuesas.size()) posible=false;
		else if (respuesas.size()*4!=cadena.size() )
			posible=false;
		while(k<cadena.size() and posible)
		{
			for (auto e: respuesas)
			{
				if (solucion[e.f][e.s]==0)
					solucion[e.f][e.s]=cadena[k];
				else
					posible=false;
				//else posible=false;
				++k;
			}
			rotar();
			sort(respuesas.begin(), respuesas.end());
		}
		for (i=0; i<n; ++i)
			for (j=0; j<n; ++j)
				if (solucion[i][j]==0)
					posible=false;
		if (posible)
		{
			for (i=0; i<n; ++i)
			for (j=0; j<n; ++j)
				printf("%c", solucion[i][j]);
			printf("\n");
		}
		else cout<<"invalid grille\n";
	}
	return 0;
}