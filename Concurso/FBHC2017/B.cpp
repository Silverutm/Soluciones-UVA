#include <bits/stdc++.h>
#define s second
#define f first
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

vi pesos;

bool f(int a, int b)
{
	return a>b;
}

int main()
{
	int t, n, a, ini, tomados, vueltas, necesarios;
	cin>>t;
	for (int caso = 1; caso <= t; ++caso)
	{
		pesos.clear();

		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>a;
			pesos.pb(a);
		}

		sort(pesos.begin(), pesos.end(), f);

		ini = 0;// fin = n-1;
		tomados = n;
		vueltas = 0;
		while (tomados > 0 and ini < n)
		{
			//necesarios = max( 50 / pesos[ini], 1 );			
			if (50%pesos[ini]==0)
				necesarios = 50/pesos[ini];
			else 
				necesarios = 50/pesos[ini] + 1;
			tomados -= necesarios;

			++vueltas;
			++ini;
		}
		if (tomados < 0)
			--vueltas;

		//if( not (caso==54 or caso==324 or caso==435 or caso==461 ) )
		//	continue;
		cout<<"Case #"<<caso<<": "<<vueltas<<"\n";
		//for (auto &e: pesos)
		//	cout<<e<<" ";
		//cout<<endl;
	}
	return 0;
}