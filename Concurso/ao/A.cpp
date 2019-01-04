#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <map>
using namespace std;
int t, raiz;
string s, s1;
char matriz[105][105];
bool caso;
map <int, int> cuadrados;

void pasar()
{
	int i, j, k=-1;
	for (i=1; i<=raiz; ++i)
		for (j=1; j<=raiz; ++j)
			matriz[i][j]=s1[++k];
	return;
}

void resolver()
{
	int i, j, k=-1;
	for (j=1; j<=raiz and caso; ++j)
		for (i=1; i<=raiz and caso; ++i)
			if (matriz[i][j]!=s1[++k]) caso=false;
	
	k=-1;
	for (j=raiz; j>=1 and caso; --j)
		for (i=raiz; i>=1 and caso; --i)
			if (matriz[i][j]!=s1[++k]) caso=false;				

	k=-1;
	for (i=raiz; i>=1 and caso; --i)
		for (j=raiz; j>=1 and caso; --j)		
			if (matriz[i][j]!=s1[++k]) caso=false;

	return;
}

int main()
{
	int i;
	cin>>t;
	getline(cin, s);
	for (i=1; i<=105; ++i)
		cuadrados[i*i]=i;

	for (i=1; i<=t; ++i)
	{
		getline(cin, s);
		s1="";
		caso=true;
		for (auto c:s)
			if (isalpha(c) )
				s1 = s1+c;
		raiz=cuadrados[s1.size()];
		if (raiz==0) caso=false;
		else 
		{
			pasar();
			resolver();
		}
		if (caso)
			cout<<"Case #"<<i<<":\n"<<raiz<<"\n";
		else cout<<"Case #"<<i<<":\nNo magic :(\n";
	}
	return 0;
}