#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
pair <int, int> ii;
vector <int> vi;
char matriz[310][310], n, m;

void buscar(int i, int j)
{
	if (matriz[i][j]!='.') return;
	
	matriz[i][j]='w';
	buscar(i+1, j);
	buscar(i-1, j);
	buscar(i, j+1);
	buscar(i, j-1);
}

int main()
{
	int i, j,n2, m2, f, c, m2, n2;
	while (scanf("%d %d", &n, &m)==2)
	{
		m3 = 3*m+1; n3 = 3*n+1;
		m2 = m<<1; n2 = n<<1;
		for ( i = 0; i <= m3; ++i)
			matriz[0][i] = matriz[n3][i] = '#';
		for ( i = 0; i <= n3; ++i)
			matriz[i][0] = matriz[i][m3] = '#';

		for ( i = 1; i <= n; ++i)
			for ( j = 1; j <= m; ++j)
			{
				scanf("%c", &matriz[i+n][j+m]);
				matriz[i][j] = matriz[i][j+m] = matriz[i][j+m2] =
				matriz[i+n][j]  = matriz[i+n][j+m2] =
				matriz[i+n2][j] = matriz[i+n2][j+m] = matriz[i+n2][j+m2] =
				matriz[i+n][j+m];
			}
		buscar(1+n,1+m);

		scanf("%d", &q);
		while (q--)
		{
			scanf("%d %d", &f, &c);
			//vertical arriba

			//vertical abajo

			//horizontal derecha


		}

	}
	return 0;
}



