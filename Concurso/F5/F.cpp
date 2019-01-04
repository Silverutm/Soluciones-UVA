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
vi Lista[70009];
bitset <70009> visitado;
int n, c, tam,sig, gi, vgi[4];

void isconected(int v)
{
	visitado[v]=true;
	for (auto u: Lista[v])
		if (!visitado[u])
			isconected(u);
}

void gradoimpar()
{
	gi=0;
	for (int i=n; i<tam; ++i)
	{
		if ( Lista[i].size()%2 )
		{
			vgi[gi]=i;
			++gi;
			if (gi==3) return;
		}
	}
}

int elotro(int i, int e)
{
	if (Lista[e][0]==i)
		return Lista[e][1];
	return Lista[e][0];
}

int minielemen(int i)
{
	int res=n+40, otro;
	sort(Lista[i].begin(), Lista[i].end());
	for (auto e:Lista[i])
	{
		otro=elotro(i, e);
		if ( Lista[ otro ].size()==1 )
			return e;
		if (otro>=tam) return e;
		//if (Lista[e].size()==2) res=min(res, e);
	}
	return Lista[i][0];
}

int main()
{
	int i, k, a,res, temp;
	bool conectada;
	vi provisional;
	while (scanf("%d %d", &n, &c)==2)
	{
		sig=tam=n+c;
		temp=2*n+c;
		for (i=0; i<temp; ++i)
			Lista[i].clear();
		visitado.reset();
		//Lista.resize(2*n+c+5);
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
			provisional.clear();
			for (auto e:Lista[i])
				if (Lista[e].size()==1)
				{
					Lista[e].pb(sig);
					Lista[sig].pb(i); Lista[sig].pb(e);
					provisional.pb(sig);
					++sig; 
				}
			for (auto e:provisional)
				Lista[i].pb(e);
		}
		isconected(0);
		conectada=true;
		for (i=0; i<sig; ++i)
			if (!visitado[i])
			{ 
				conectada=false; 
				break;
			}
		if (conectada)
		{	gradoimpar();
			if (gi==0)  res=0;
			else if (gi!=2) conectada=false;
			else
			{
				res=min( minielemen( vgi[0]  ), minielemen( vgi[1]  ) );
				//res=min(
				//	*min_element( Lista[ vgi[0] ].begin(),Lista[ vgi[0] ].end() ),
				//	*min_element( Lista[ vgi[1] ].begin(),Lista[ vgi[1] ].end() )
				//	);

			}
		}
		if (conectada) printf("%d\n",res );
		else printf("-1\n");
	}
	return 0;
}