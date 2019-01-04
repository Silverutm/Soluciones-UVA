#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef vector <int> vi;
typedef long long ll;
typedef pair <int , int> ii;
vector <ii> Lista[500];
char matriz[60][60];
int pintados[60][60];
bool distancias[60][60];
int vecinos[310][310];
int color;
int cantidaddecolores;
int f, c, t;

bool taken[301];
priority_queue<ii> pq;

void process(int vtx)
{
	taken[vtx] = 1;
	for (int j = 0; j < Lista[vtx].size(); ++j)
	{
		ii v =  Lista[vtx][j];
		if (!taken[v.first])
		{
			pq.push(ii(-v.second, -v.first));
		}
	}
}

void buscar(int i, int j)
{
	pintados[i][j] = color;
	if (matriz[i+1][j]=='X' and !pintados[i+1][j] )
		buscar(i+1, j);
	if (matriz[i-1][j]=='X' and !pintados[i-1][j] )
		buscar(i-1, j);
	if (matriz[i][j+1]=='X' and !pintados[i][j+1] )
		buscar(i, j+1);
	if (matriz[i][j-1]=='X' and !pintados[i][j-1] )
		buscar(i, j-1);
}



void amplitud(int i, int j, int cuenta)
{
	//distancias[i][j] = cuenta;
	queue < pair<ii, int> > cola;
	cola.push( make_pair( ii(i,j), cuenta ) );
	while (!cola.empty())
	{
		auto e = cola.front(); cola.pop();
		i = e.fi.fi; j = e.fi.se; cuenta = e.se;
		distancias[i][j] = 1;
		if (i==0 or j==0 or i==f+1 or j==c+1) continue;
		if (pintados[i][j]!= color)
		{
			if (vecinos[color][ pintados[i][j] ]==-1  )
			{
				vecinos[color][ pintados[i][j] ] = cuenta;
				vecinos[ pintados[i][j] ][color] = cuenta;
			}
			else
			{
				vecinos[color][ pintados[i][j] ] = min(vecinos[color][ pintados[i][j] ], cuenta);
				vecinos[ pintados[i][j] ][color]=vecinos[color][ pintados[i][j] ];
			}
			//cout<<i<<" "<<j<<" . "<<cuenta<<endl;
			continue;
		}

		if ( pintados[i+1][j]!=color and not distancias[i+1][j] )
			cola.push( make_pair( ii(i+1,j), cuenta+1 ) );
			//amplitud(i+1, j, cuenta+1);
		if (pintados[i-1][j] !=color and not distancias[i-1][j] )
			cola.push( make_pair( ii(i-1,j), cuenta+1 ) );
			//amplitud(i-1, j,cuenta+1);
		if ( pintados[i][j+1]!=color and not distancias[i][j+1] )
			cola.push( make_pair( ii(i,j+1), cuenta +1) );
			//amplitud(i, j+1, cuenta+1);
		if (pintados[i][j-1]!=color and not distancias[i][j-1])
			cola.push( make_pair( ii(i,j-1), cuenta+1 ) );
			//amplitud(i, j-1, cuenta+1);
	}
		

}

void limpiar()
{
	int i, j;
	for( i=1; i<=f; ++i)
		for( j=1; j<=c; ++j)	
			distancias[i][j]=0;
}
int main()
{
	scanf("%d", &t);
	int i, j, f1, c1;
	while (t--)
	{
		//memset(pintados, 0, sizeof pintados);
		//memset(vecinos, -1, sizeof vecinos);
		color =0;		

		scanf("%d %d", &f, &c);
		for ( i = 1; i <= f; ++i)
			for ( j = 1; j <= c; ++j)
				scanf("%c", &matriz[i][j]);
		f1=f+1; c1=c+1;
		for (int i = 0; i <= f1; ++i)
			matriz[i][0] = matriz[i][c1] ='.';
		for (int j = 0; j <= c1; ++j)
			matriz[0][j] = matriz[f1][j] ='.';



		for ( i = 1; i <= f; ++i)
			for ( j = 1; j <= c; ++j)
				if (matriz[i][j]=='X' and !pintados[i][j] )
				{					
					++color;
					buscar(i, j);
				}

		cantidaddecolores= color;
		for ( i = 1; i <= f; ++i)
			for ( j = 1; j <= c; ++j)
				if ( pintados[i][j] )
				{
					//memset(distancias, 0, sizeof distancias);
					limpiar();
					color = pintados[i][j];
					amplitud(i, j, 0);
				}

		for (int i = 0; i <= cantidaddecolores; ++i)
		{
			Lista[i].clear();
		}
		for (int i = 1; i <= cantidaddecolores; ++i)
			for (int j = i+1; j <= cantidaddecolores; ++j)
				if (vecinos[i][j]!=-1 )
				{
					//cout<<i<<" "<<j<<" "<<vecinos[i][j]<<endl;
					Lista[i].push_back(ii(vecinos[i][j], j) );
					Lista[j].push_back(ii(vecinos[i][j], i) );
				}
		int N = cantidaddecolores;
		//taken.assign(N,0);
		for (i=0; i<= N; ++i) taken[i]=0;
		process(0);
		int mst_cost = 0;
		int u, w;
		
		while(!pq.empty())
		{
			ii front = pq.top();
			pq.pop();
			u = -front.second;
			w = -front.first;
			if (!taken[u])
			{
				mst_cost += w;
				process(u);
			}
		}
		printf("%d\n",mst_cost );
	}
	return 0;
}