#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string s, res;
int arreglo[23][12], i, veces[13];

void magia()
{
	s[i]--;
}

int main()
{
	int j;
	while (cin>>s)
	{
		//memset(arreglo, 0, sizeof arreglo);
		memset(veces, 0, sizeof veces);
		//res=s;
		//++arreglo[i][ s[i] ];
		for ( i=0; i<s.size(); ++i  )
		{	
			/*for (j=0; j<=9; ++j)
				arreglo[i][ j ]=arreglo[i-1][ j ];
			++arreglo[i][ s[i] ];
			if ( arreglo[i][ s[i] ] )
			{
				magia();
				break;
			}*/
		}
	}
	return 0;
}