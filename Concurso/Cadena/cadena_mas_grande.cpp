#include <bits/stdc++.h>
using namespace std;
vector <int> Lista[500], Papas[500];
bool tocado[500];
int main()
{
	int ini, fin;
	string s;
	while ( getline(cin,s) )
	{
		fin = s[ s.size() -1 ];
		if (fin == 'x') continue;
		ini = tolower( s[0] );
		tocado[ini] = tocado[fin] =true;
		Lista[ini].push_back( fin );
		Papas[fin].push_back( ini );
	}

	//return 0;
	int tot = 0;
	for (int i = 0; i < 500; ++i)
	{
		if ( Lista[i].size() == 0 and not tocado[i]) continue;
		
		printf("%c:\t", i);
		cout<<Lista[i].size()<<"\t";
		for (auto &e:Lista[i])
			printf("%c ", e);
		printf("\n");
		tot +=Lista[i].size();
	}
	printf("%d\n",tot );

	printf("\n\n\n\n");

	for (int i = 0; i < 500; ++i)
	{
		if ( Papas[i].size() == 0 and not tocado[i]) continue;
		
		printf("%c:\t", i);
		cout<<Papas[i].size()<<"\t";
		for (auto &e:Papas[i])
			printf("%c ", e);
		printf("\n");
	}
	return 0;
}