#include <iostream>
#include <map>
using namespace std;
map <string, int> mapa;
int main()
{
	string s, id;
	getline (cin, s);
	int contador = 0;
	int n=1;
	while ( getline (cin, s, ',') )
	{
		cout<<++contador<<",";
		getline (cin, id, ',');
		if (not  mapa[id] )
		{
			mapa[id] = n;
			++n;
		}
		cout<<mapa[id]<<",";
		getline(cin,s);
		cout<<s<<"\n";
	}
	return 0;
}