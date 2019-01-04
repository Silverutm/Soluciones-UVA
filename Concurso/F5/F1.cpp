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
vi  Lista[40009];
bitset <40009> visitado;
int n, c, tam, gi, vgi[4], tamanos[40009];

void isconected(int v)
{
	queue <int> cola;
	cola.push(v);
	visitado[v]=true;
	while (!cola.empty())
	{
		v=cola.front(); cola.pop();
		for (auto u: Lista[v])
			if (!visitado[u])
			{
				visitado[u]=true;
				cola.push(u);
			}
	}
	
}

void gradoimpar()
{
	gi=0;
	for (int i=n; i<tam; ++i)
	{
		if ( tamanos[i]%2 )
		{
			vgi[gi++]=i;
			if (gi==3) return;
		}
	}
}
int minielemen(int i)
{
	int res=n+40;
	for (auto e:Lista[i])
		if (Lista[e].size()==2) res=min(res, e);
	return res;
}
int main()
{
	int i, k, a,res;
	bool conectada;
	//vi provisional;
	while (scanf("%d %d", &n, &c)==2)
	{
		tam=n+c;
		for (i=0; i<tam; ++i)
			Lista[i].clear();
		visitado.reset();
		//Lista.resize( n+c+5 );
		memset(tamanos, 0, sizeof tamanos);
		for (i=0; i<c; ++i)
		{
			scanf("%d", &k);
			if (k==0) visitado[i+n]=true;
			else while (k--)
			{
				scanf("%d", &a);
				Lista[i+n].pb(a);
				Lista[a].pb(i+n);
			}
		}
		for (i=n; i<tam; ++i)
		{
			//provisional.clear();
			tamanos[i]=Lista[i].size();
			for (auto e:Lista[i])
				if (Lista[e].size()==1)
					++tamanos[i];
		}
		isconected(0);
		conectada=true;
		for (i=0; i<tam; ++i)
			if (!visitado[i])
			{ 
				conectada=false; 
				break;
			}
		if (conectada)
			gradoimpar();
		if (gi==0)  res=0;
		else if (gi!=2 ) conectada=false;
		else
			res=min( minielemen( vgi[0]  ), minielemen( vgi[1]  ) );
		if (conectada) printf("%d\n",res );
		else printf("-1\n");
	}
	return 0;
}