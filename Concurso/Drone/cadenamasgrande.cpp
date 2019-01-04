#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{ return a<b ? b:a;}
long long total;
int main()
{
	string cadena;
	int mayor=0;
	while( getline(cin, cadena) )
	{
		mayor= max(mayor, cadena.size() );
		total += cadena.size();
	}
	cout<<mayor<<endl<<total<<endl;
	return 0;
}