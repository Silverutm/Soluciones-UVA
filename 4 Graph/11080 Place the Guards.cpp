#include <bits/stdc++.h>
using namespace std;
vector <int> Lista[205];
int cuenta, color[205], negros;
bool bipartita;

void pintar(int v)
{
	for (auto &u: Lista[v])
		if (color[u]==-1)
		{
			++cuenta;
			color[u] = 1 -  color[v];
			if ( color[u] ) ++negros;

			pintar(u);
		}
		else if (color[u]== color[v])
		{
			bipartita= false;
			break;
		}
}

int main()
{
	int n, m, v, t, total, a, b;
	cin>>t;
	while (t--)
	{		
		cin>>n>>m;
		for (v = 0; v < n; ++v)
			Lista[v].clear();
		memset(color, -1, sizeof color);
		
		while(m--)
		{
			cin>>a>>b;
			Lista[a].push_back(b);
			Lista[b].push_back(a);
		}

		bipartita = true;
		total = 0; 
		for (v = 0; v < n and bipartita; ++v)
			if (color[v]== -1 )
			{
				cuenta = negros = color[v] = 0;
				pintar(v);
				total += max(min(negros, cuenta + 1 - negros ), 1);
			}
		if (bipartita)
			cout<<total<<"\n";
		else printf("-1\n");

		/*for (v = 0; v < n; ++v)
			cout<<color[v]<<" ";
		cout<<"\n";*/

	}
	return 0;
}