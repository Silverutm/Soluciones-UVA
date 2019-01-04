#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char matriz[200][200];
char arreglo[200];
int main()
{
	int n, i, j, alma, almi, k;
	string s;
	char ant;
	cin>>n;
	for ( k = 1; k <= n; ++k)	
	{
		cin>>s;
		memset (matriz, 0, sizeof matriz);
		memset (arreglo, 0, sizeof arreglo);
		alma = almi = i = 100; j=0; ant = '-';

		for (auto & e: s)
		{			
			
			if (e=='R')
			{
				if ( ant=='\\' ) --i;
				matriz[i][j] = '/';				
			}
			else if (e == 'F' )
			{
				if ( ant!='\\' and ant!='-') ++i;
				matriz[i][j] = '\\';				
			}
			else
			{
				if ( ant=='\\' ) --i;
				matriz[i][j] = '_';
			}

			arreglo[i] = j;
			alma = min(alma, i);
			almi = max(almi, i);
			ant = matriz[i][j];

			if (e=='F') ++i; else if (e=='R') --i;
			++j;
		}
		cout<<"Case #"<<k<<":"<<endl;
		for ( i = alma; i <= almi; ++i)
		{
			cout<<"| ";
			for ( j = 0; j <= arreglo[i]; ++j)
				if ( matriz[i][j] ) cout<<matriz[i][j];
				else cout<<" ";
			cout<<endl;
		}
		cout<<"+";
		for ( i = 0; i <= s.size()+1; ++i)
			cout<<"-";

		cout<<"\n\n";

	}
	return 0;
}
