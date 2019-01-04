#include <bits/stdc++.h>
#define tam 305
using namespace std;

vector <int> Lista[tam];
bool bipartita;
int color[tam];

void pintar(int v)
{	
	for (auto &u:Lista[v])
		if (color[u]==-1)
		{
			color[u] = 1 - color[v];
			pintar(u);
		}
		else if ( color[u] ==  color[v])
		{
			bipartita = false;
			break;
		}
}

int main()
{
	int n, v, a, b;
	while (cin>>n and n)
	{
		for (v = 1; v <= n; ++v)
			Lista[v].clear();
		memset(color, -1, sizeof color);

		while (cin>>a>>b and a)
		{
			Lista[a].push_back(b);
			Lista[b].push_back(a);
		}

		bipartita = true;

		for (v = 1; v <= n and bipartita; ++v)
			if (color[v]== -1 )
			{
				color[v] = 0;
				pintar(v);
			}
		if (bipartita) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}