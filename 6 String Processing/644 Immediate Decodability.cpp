#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector < string > vs;
set < string > conjunto;
string s;
int i;
bool b;

void resolver()
{
	b=true;
	for (auto cad: vs)
	{
		if ( conjunto.find(cad)!=conjunto.end() )
			b=false;
	}
	cout<<"Set "<<++i;
	if (b) cout<<" is immediately decodable\n";
	else cout<<" is not immediately decodable\n";
	vs.clear();
	conjunto.clear();
}

void codificar()
{
	string cad; cad.clear();
	for (int i = 0; i < s.size()-1; ++i)
	{
		cad.push_back(s[i]);
		conjunto.insert(cad);
	}
	vs.push_back(s);
}

int main()
{
	while (cin>>s)
	{
		if (s=="9") resolver();
		else codificar();
	}
	return 0;
}