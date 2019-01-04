#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

string sumar(string s, int k)
{
	for (auto & c:s)
	{
		if (isalpha(c))
			c = c- 'A' +1;
		else c=0;
		c =(c+ k)%27;
		if ( c )
			c+='A'-1;
		else c=' ';
	}
	return s;
}

int main()
{
	string s, dic[105];
	int n=0, maxi, rm, p, k;
	while (getline( cin, s) and s!="#")
	{
		dic[n++]=s;
	}	
	getline( cin, s);
	maxi = 0; rm = 0;
	for (k=0; k<=26; ++k)
	{
		p=0;
		for (int i = 0; i < n; ++i)
		{
			if ( strstr( s.c_str()  ,sumar(dic[i], k).c_str() )!=NULL )
				++p;
		}
		if (p>rm) {maxi=k;rm=p;}
	}
	for (auto & c:s)
	{
		if (isalpha(c))
			c = c- 'A' +1;
		else c=0;
		c =(c- maxi + 27)%27;
		if ( c )
			c+='A'-1;
		else c=' ';	
	}
	int c=0;
	string x=" ";
	string pch = strtok (s.c_str(),x.c_str());
	while (pch != "")
	{
		if (c+strlen(pch.c_str())>60)
		{
			printf ("\n");
			c= strlen(pch.c_str());
		}
		else c+=strlen(pch.c_str());
		printf ("%s",pch.c_str());
		pch = strtok (NULL, x.c_str());
	}
	return 0;
}