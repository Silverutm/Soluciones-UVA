#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 505
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;

int mat[tam][tam], m, n, visitado[tam][tam];
char c;
ii meta;

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin>>c;
			mat[i][j] = c - '0';
			//cout<<mat[i][j]<<" ";
		}
		//cout<<endl;
	//return 0;
	meta = mk(m-1, n-1);

	ii ini(0,0);
	visitado[0][0] = 1;
	queue<ii> cola;
	cola.push(ini);
	while ( !cola.empty() )
	{
		ii ac = cola.front(); cola.pop();

		if (ac == meta ) break;
		int p = mat[ac.f][ac.s];
		int d = visitado[ac.f][ac.s];

		if ( ac.f - p >= 0  )
		{
			if ( not visitado[ac.f - p][ac.s] )
			{
				visitado[ac.f - p][ac.s] = d + 1;
				cola.push( mk(ac.f - p,ac.s) );
			}

		}

		if ( ac.f + p < m  )
		{
			if ( not visitado[ac.f + p][ac.s] )
			{	
				visitado[ac.f + p][ac.s] = d + 1;
				cola.push( mk(ac.f + p,ac.s) );
			}
		}

		if ( ac.s - p >= 0  )
		{
			if ( not visitado[ac.f][ac.s - p] )
			{
				visitado[ac.f][ac.s - p] = d + 1;
				cola.push( mk(ac.f,ac.s-p) );
			}
		}

		if ( ac.s + p < n  )
		{
			if ( not visitado[ac.f][ac.s + p] )
			{
				visitado[ac.f][ac.s + p] = d + 1;
				cola.push( mk(ac.f,ac.s+p) );
			}
		}
	}

	if (visitado[m-1][n-1] == 0) printf("IMPOSSIBLE\n");
	else printf("%d\n",visitado[m-1][n-1]-1 );
	return 0;
}