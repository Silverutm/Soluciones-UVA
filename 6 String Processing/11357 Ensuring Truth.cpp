#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int n, i, arreglo[500];
string s;

bool siguiente()
{
	bool c = true;
	memset(arreglo, -1, sizeof arreglo);
	while ( s[i]!=')' )
	{
		if (s[i]=='&') {++i; continue;}
		if ( not isalpha( s[i] ) )
		{
			++i;
			if ( arreglo[ s[i] ]==1 ) c = false;
			else arreglo[ s[i] ]=0;
		}
		else
		{			
			if ( arreglo[ s[i] ]==0 ) c = false;
			else arreglo[ s[i] ]=1;			
		}
		++i;
	}
	i +=3;
	return c;
}

int main()
{	
	bool p;
	cin>>n;
	while (n--)
	{
		cin>>s;
		p = false;
		i = 1;		
		while ( i < s.size() and not ( p = siguiente() ) );	
		if (p)	cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}