#include <bits/stdc++.h>
#define s second
#define f first
#define mk make_pair
#define pb push_back
#define tam 105
#define INF 10000000000000LL
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

ll matriz[tam][tam], g, tabla[3][5005][tam], r;
int w, n, m, k, a, b, origen[5005], destino[5005];

ll dinamica(int cuantos, int procesando /*menor*/, int estoy )
{
	if (procesando == k) return 0;
	//cout<<cuantos<<" "<<procesando<<" "<<estoy<<endl;
	ll &t = tabla[cuantos][procesando][estoy];
	if ( t!= -1 ) return t;

	if ( cuantos == 0 ) //procesando deberia tener o tengo, irlo a recoger
		return t = matriz[estoy][ origen[procesando] ] + dinamica(1, procesando, origen[procesando]);

	if ( cuantos == 1 )  //irlo a dejar o recoger el otro
	{
		if ( procesando!=k-1 )
			return t = min( matriz[estoy][ destino[procesando] ] + dinamica(0, procesando +1, destino[procesando] ),
						matriz[estoy][ origen[ procesando+1 ] ] + dinamica(2, procesando, origen[ procesando+1 ])     );
		else return t = matriz[estoy][ destino[procesando] ];
	}

	//if ( cuantos == 2 ) irlo a dejar
		return t = matriz[estoy][ destino[procesando] ] + dinamica(1, procesando+1, destino[procesando]);
}

int main()
{
	bool posible;
	cin>>w;
	for (int caso = 1; caso <= w; ++caso)
	{		
		cin>>n>>m>>k;

		memset(tabla, -1, sizeof tabla);

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				matriz[i][j] = INF;

		for (int i = 0; i < n; ++i)
			matriz[i][i] = 0LL;

		while (m--)
		{
			cin>>a>>b>>g;
			--a; --b;
			matriz[b][a] = matriz[a][b] = min( matriz[a][b], g );
		}

		for (int kk = 0; kk < n; kk++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					matriz[i][j] = min(matriz[i][j], matriz[i][kk] + matriz[kk][j]);

		posible = true;
		for (int i = 0; i < k; i++)
		{
			cin>>origen[i]>>destino[i];
			--origen[i]; --destino[i];
			if ( matriz[0][ origen[i] ] == INF or matriz[0][ destino[i] ] == INF)
				posible = false;
		}
		//cout<<"hyola\n";
		if ( posible )
			r = dinamica(0, 0, 0);
		else r = -1;

		cout<<"Case #"<< caso <<": "<< r <<"\n";

	}
	return 0;
}