#include <iostream>
using namespace std;
int main()
{
	int n, i,j, k, i1, j1, k1;
	string s, sn;
	bool encontrado, caos;
	cin>>n;
	while (n--)
	{
		cin>>s;
		i=0; j = s.size() / 3 + 1; k = 2*j;
		encontrado = false;
		caos = false;
		while (not caos)
		{						
			caos = true;
			for ( i1 = i, j1 = j; i1 < j and caos; ++i1, ++j1)			
					if ( s[i1]!=s[j1] ) caos= false;				
			
			if ( not caos )
			{
				++j;
				k += 2;
			}
			else
			{
				i1 = i; k1 = k;
				while ( k1<s.size() and caos) 
				{
					if ( s[i1]!=s[k1]  ) caos=false;
					++i1; ++k1;
				}
			}
		}
		sn.clear();
		i1=0;
		if (caos) while (sn.size() <8 ) sn.push_back( s[i1++%j] );
		cout<<sn<<"..\n";
	}
	return 0;
}