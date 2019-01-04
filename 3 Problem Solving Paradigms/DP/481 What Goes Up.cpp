#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;

vector <int> lista, papa, tam, indice;


void imprime(int res)
{
	//int res= indice[ tam.size()-1 ];
	//while (res!=-1)
	if (res!=-1)
	{
		//cout<<lista[res]<<endl;
		//res	= papa[res];
		imprime(papa[res]);
		cout<<lista[res]<<endl;
	}
}

int main()
{
	int a,  i, j;
	while (cin>>a)
	{
		lista.pb(a); 
		papa.pb(-1);
		indice.pb(-1);
	}
	//tam.pb( lista[0] );
	for (j=0; j<lista.size(); ++j)
	{
		auto v=lista[j];
		auto m=lower_bound(tam.begin(), tam.end(), v  );
		i = m-tam.begin();
		if ( i==tam.size() )
		{
			if (tam.size())
				papa[j]=indice[ tam.size()-1 ];
			tam.pb( v );
			indice[ tam.size()-1 ] = j;
		}
		else
		{
			//--i;
			tam[i]=v;
			if (i!=0)
			papa[j]= indice[i-1];
			//papa[j]= papa[ indice[i] ];
			indice[ i ]=j;

		}
	}
	cout<<tam.size()<<"\n-\n";
	imprime( indice[ tam.size()-1 ] );

	return 0;
}