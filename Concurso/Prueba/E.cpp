#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
using namespace std;
typedef pair <int, int> ii;
typedef vector < ii > vii;
//multiset < int > conjunto;
map <int, int> conjunto;
int n, m, c, arreglo[1000009];

bool revisa(int a, int b)
{
	if ( max(a,b)-min(a,b) <=c )
		return true;
	return false;
}

int main()
{
	int i, contador=0, i_1, j_1, j;
	scanf("%d %d %d", &n, &m, &c);
	if (m>n) {printf("NONE\n"); return 0;}
	
	for (i=0; i<n; ++i)
		scanf("%d", &arreglo[i]);

	for (i=0; i<m; ++i)
		++conjunto[ arreglo[i] ];

	auto inicio=conjunto.begin();
	auto fin= conjunto.rbegin();

	if ( revisa( (*inicio).first, (*fin).first )  )
	{
		printf("1\n");
		++contador;
	}
	for (i=1, j=m  ;j<n; ++j, ++i)
	{

		j_1=arreglo[j];
		conjunto[ j_1 ]++;

		i_1=arreglo[i-1];
		conjunto[ i_1 ]--;
		if ( !conjunto[ i_1 ] ) conjunto.erase( i_1 );

		//if ( !conjunto[ j_1 ] ) contador.erase( i_1 );


		inicio=conjunto.begin();
		fin= conjunto.rbegin();	

		if ( revisa( (*inicio).first, (*fin).first )  )
		{
			printf("%d\n", i+1);
			++contador;
		}
	}
	if (contador==0)
			printf("NONE\n");
	return 0;
}
