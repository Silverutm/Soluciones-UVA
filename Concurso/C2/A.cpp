#include <iostream>
using namespace std;
int main()
{	
	string w="\"";
	string s, sub="", senteros, scadenas;
	getline(cin,s);
	bool posible;
	senteros=w;
	scadenas=w;
	int i=0, j, cadenas=0, enteros=0;
	for (i=0; i<s.size(); ++i)
	{
		sub="";
		while (i<s.size() and s[i]!=',' and s[i]!=';')
		{
			sub= sub+s[i];
			++i;
		}
		posible=true;
		if ( not sub.size())
		{	
			posible=false;			
		}
		else if (sub[0]=='0' and sub.size()>1) posible=false;
		for (j=0; j<sub.size() and posible; ++j)
			if (sub[j]<'0' or sub[j]>'9' )
				posible=false;		
		if (posible)
		{
			if (enteros)
				senteros = senteros +","+sub;
			else senteros = senteros +sub;
			++enteros;
		}
		else 
		{
			if (cadenas)
				scadenas = scadenas +","+sub;
			else scadenas = scadenas +sub;
			++cadenas;
		}
	}
	if (s[s.size()-1]==',' or  s[s.size()-1]==';') 
	{
			if (cadenas)
				scadenas = scadenas +",";
			else scadenas = scadenas ;
			++cadenas;
	}
	senteros +=w;
	scadenas+=w;
	if (not enteros) senteros="-";
	if (not cadenas) scadenas="-";
	cout<<senteros<<endl<<scadenas<<endl;

	return 0;
}