#include <bits/stdc++.h>
#define tam 55
#define f first
#define s second
#define mk make_pair
using namespace std;
typedef pair<int,int> ii;

char escenario[tam][tam];
int distancias[tam][tam];
int n, m;
ii r, e;
string s;
queue<ii> cola;

void imprime()
{
	int i, j;
	for (i = 0; i <= n+1; ++i)
	{
		for (j = 0; j <= m+1; ++j)
		{
			cout<<escenario[i][j];
		}
		cout<<endl;
	}
	cout<<endl;

	for (i = 1; i <= n; ++i, cout<<endl)
		for (j = 1; j <= m; ++j)
			cout<<distancias[i][j]<<" ";

}
int main()
{	
	int i, j;
	scanf("%d %d", &n, &m);

	for (i = 0; i <= n+1; ++i)
	{
		for (j = 0; j <= m+1; ++j)
		{
			escenario[i][j]='#';
		}
	}
	for (i = 1; i <= n; ++i)
	{
		cin>>s;
		for (j = 1; j <= m; ++j)
			escenario[i][j] = s[j];
			//scanf("%c", &escenario[i][j] );			
	}
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			if (escenario[i][j] == 'R')
				r = ii{i, j};
			else if (escenario[i][j] == 'E')
			{
				e =  ii{i,j};
				escenario[i][j] = '#';
			}
		//return 0;
	int x, y, d;
	cola.push( e );
	//escenario[]
	int z=0;
	while( !cola.empty() )
	{
		auto par = cola.front(); cola.pop();
		y = par.f; x = par.s; d = distancias[y][x];		
		//if ( escenario[y][X]=='#' ) continue;

		//distancias[y][x] = d;
		if (escenario[y+1][x] != '#' and distancias[y+1][x]==0) 
		{
			cola.push( ii{y+1,x} );
			distancias[y+1][x] = d + 1;
			//cout<<distancias[y+1][x]<<endl;
		}
		if (escenario[y-1][x] != '#' and distancias[y-1][x]==0) 
		{
			cola.push( ii{y-1,x} );
			distancias[y-1][x] = d + 1;
			//cout<<distancias[y-1][x]<<endl;
		}
		if (escenario[y][x+1] != '#' and distancias[y][x+1]==0) 
		{
			cola.push( ii{y,x+1} );
			distancias[y][x+1] = d + 1;
			//cout<<distancias[y][x+1]<<endl;
		}
		if (escenario[y][x-1] != '#' and distancias[y][x-1]==0) 
		{
			cola.push( ii{y,x-1} );
			distancias[y][x-1] = d + 1;
			//cout<<distancias[y][x-1]<<endl;
		}
		//cout<<cola.size()<<" ";
		if (++z==100) break;
		//cout<<cola.size();
	}
	//imprime();
	//cout<<
	y = r.f; x = r.s;
	cin>>s;
	//cout<<s<<endl;
	int total=1000000;
	for (auto e:s)
	{
		if (e=='R' and escenario[y][x+1]!='#' )
		{
			x += 1;
			total =  min(total, distancias[y][x]);			
		}
		else if (e=='L' and escenario[y][x-1]!='#' )
		{
			x -= 1;
			total =  min(total, distancias[y][x]);
		}
		else if (e=='D' and escenario[y+1][x]!='#' )
		{
			y += 1;
			total =  min(total, distancias[y][x]);
		}
		else if (e=='U' and escenario[y-1][x]!='#' )
		{
			y -= 1;
			total =  min(total, distancias[y][x]);
		}
	}
	printf("%d\n",total );
	return 0;
}