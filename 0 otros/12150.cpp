#include <bits/stdc++.h>
using namespace std;
int n = 0;
vector<int> v; 

void solve()
{
	v.assign(n, -1);		//lenar vector con -1
							//posicion ocupada

	bool res = true;		//supongo que tiene solucion

	for (int i = 0; i < n; ++i)
	{
		int c, delta; 
		scanf("%d %d", &c, &delta);
		//si el lugar original del jugador estra dentro de los limites
		//y no es un lugar ocupado
		if(i+delta >= 0 and i+delta < n and v[i+delta] == -1)
			v[i+delta] = c;
		else	//en caso contrario no hay solucion
			res = false;
	}

	if(res)	//si hay solucion imprimo la respuesta
	{
		for (int i = 0; i < n; ++i)
		{
			if(i)
				printf(" ");
			printf("%d", v[i]);
		}
	}
	else
		printf("-1");

	printf("\n");

}

int main()
{
	while(scanf("%d", &n) == 1 and n)
		solve();
	return 0;
}