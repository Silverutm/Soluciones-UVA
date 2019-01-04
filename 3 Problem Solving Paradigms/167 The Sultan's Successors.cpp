#include <iostream>
#include <vector>
#include <bitset>
#include <cstdio>
using namespace std;
typedef vector< int > vi;
vi sol(9);
vector < vi > respuestas;
bitset <30> rows, d1, d2;


void buscar(int c)
{
	if (c==9)
	{
		//vi temp(sol+1, sol+8);
		respuestas.push_back( sol );
	}
	for (int i=1; i<=8; ++i)
		if ( !rows[i] and  !d1[ i + c ] and !d2[ i-c + 8 ] )
		{
			rows[i] =  d1[ i + c ] = d2[ i-c + 8 ]=true;
			sol[c]=i;
			buscar(c+1);
			rows[i] =  d1[ i + c ] = d2[ i-c + 8 ]=false;
		}
	return ;
}

int matriz[70][70], maxi;

int main()
{
	int i, j, k, l, temp;
	rows.reset(); d1.reset(); d2.reset();
	buscar(1);
	cin>>k;
	while (k--)
	{
		for (i=1; i<=8; ++i)
			for (j=1; j<=8; ++j)	
				cin>>matriz[i][j];
		maxi=0;
		for (l=0; l<respuestas.size(); ++l )
		{
			temp=0;
			for (j=1; j<=8; ++j)
				temp+=matriz[ respuestas[l][j] ][ j ];
			if (temp>maxi) maxi=temp;
		}
		printf("%5d\n", maxi);
	}
	return 0;
}