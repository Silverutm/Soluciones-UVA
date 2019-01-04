#include <bits/stdc++.h>
#define f first
#define s second
#define tam 1005
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <int> vi;

#define hor 0
#define ver 1
vi Lista[tam][2], col[tam], row[tam];
int color[tam], pintados[tam], ip;
bool posible;
int n, r, l, x[tam], y[tam];

bool chocan(int a, int b)
{
	return abs(a-b) <= r;
}

void pintar(int c, int u)
{
	color[u] = c;
	pintados[ip] = u; ++ip;
	for (auto &v:Lista[u][c])
	{
		if ( not posible) return;
		if (color[v]==-1)
			pintar(1-c, v);
		else if (color[v]==c)
		{
			posible = false;
			return;
		}
	}
}

int main()
{
	int i, j, k, a, b;
	scanf("%d %d %d", &n, &r, &l);
	for (i = 0; i < l; ++i)
	{
		scanf("%d %d", &y[i], &x[i]);
		--y[i]; --x[i];
		col[ x[i] ].pb(i);
		row[ y[i] ].pb(i);
	}

	for (k = 0; k < n; ++k)
		for (i = 0; i < col[k].size(); ++i)
			for (j = i+1; j < col[k].size(); ++j)
			{
				a = col[k][i]; b = col[k][j];
				if ( chocan( y[a], y[b] ) )
				{
					Lista[a][ver].pb(b);
					Lista[b][ver].pb(a);
				}
			}

	for (k = 0; k < n; ++k)
		for (i = 0; i < row[k].size(); ++i)
			for (j = i+1; j < row[k].size(); ++j)
			{
				a = row[k][i]; b = row[k][j];
				if ( chocan( x[a], x[b] ) )
				{
					Lista[a][hor].pb(b);
					Lista[b][hor].pb(a);
				}
			}

	memset(color, -1, sizeof color);
	posible = true;
	for ( i = 0; i < l; ++i)
	{
		ip = 0;
		if ( color[i]==-1 )
			pintar(hor,i);
		if (not posible)
		{
			for (j = 0; j < ip; ++j)
				color[pintados[j]] = -1;
			ip = 0; posible = true;
			pintar(ver, i);
		}
		if (not posible) break;
	}
	if (posible) printf("YES\n");
	else printf("NO\n");
	return 0;
}