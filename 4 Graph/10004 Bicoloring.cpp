#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef vector <int> vi;
vector < vi > Lista;
int color[205];
bool biparita;

int farbe(int f)
{ return f==2? 1:2; }

void pinta(int v)
{
	if (not biparita) return;
	for (auto u: Lista[v])
		if (!color[u]) 
		{
			color[u]= farbe( color[v] );
			pinta(u);
		}
		else if (color[u]==color[v]) biparita=false;
}

int main()
{
	int n, m, a, b;
	while ( scanf("%d %d", &n, &m)==2, n )
	{
		Lista.clear();
		Lista.resize(n);
		memset(color, 0, sizeof color);
		while (m--)
		{
			scanf("%d %d", &a, &b);
			Lista[a].push_back(b);
			Lista[b].push_back(a);
		}
		biparita=true;
		color[0]=2;
		pinta(0);
		if (biparita) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}
	return 0;
}