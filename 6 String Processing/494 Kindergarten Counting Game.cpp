#include <iostream>
#include <string>
#include <cstdio>
#include <cctype> 
using namespace std;

int main()
{
	string s;
	int palabras, i, espalabra;
	while (getline(cin, s) )
	{
		i= palabras = 0;
		espalabra=0;
		for ( ; i<s.size(); ++i)
		{			
			if ( isalpha(s[i]) )
				espalabra=1;	//indico que estoy en una palabra
			else
			{
				//si encuentro algo que no es una letra
				//sumo a mi contador
				//si anteriormente estaba en una palabra el contador
				//aumentara en 1, si no, solo le sumanre 0
				palabras +=espalabra;
				//indico que ya no estoy en una palabra
				espalabra=0;
			}
		}
		palabras +=espalabra;
		printf("%d\n", palabras);
	}
	return 0;
}