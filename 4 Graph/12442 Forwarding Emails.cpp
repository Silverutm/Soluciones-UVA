#include <bits/stdc++.h>
#define tam 50005
using namespace std;
int mensaje[50005], profundida[tam], representante[tam];
int papa;
bitset <tam> visitado;

void buscar(int v)
{
	buscar( mensaje[v]  );
	profundida[v] = profundida[ mensaje[v] ] + 1;
}

int main()
{
	int t,n,u,v, sol;
	cin>>t;
	for (int caso = 1; caso<=t; ++caso)
	{		
		memset(mensaje, 0, sizeof mensaje);
		memset(profundida, 0, sizeof profundida);
		memset(representante, 0, sizeof representantee);
		visitado.reset();
		cin>>n;
		for (int i = 0; i < count; ++i)
		{
			cin>>u>>v;
			mensaje[u] = v;
		}

		for (v = 1; v <= n; ++v)
		{
			if (visitado[v]) continue;

			papa = 0;				
			buscar(v);
		}

		cout<<"Case "<<caso<<": "<<sol<<"\n";
	}
	return 0;
}