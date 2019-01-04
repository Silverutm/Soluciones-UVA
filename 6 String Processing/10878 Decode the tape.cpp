#include <iostream>
#include <map>
using namespace std;
int main()
{
	string s, res="A quick brown fox jumps over the lazy dog.";
	int i=-1;
	map <string, char> mapa;
	while ( getline(cin, s) )
	{
		++i;
		cout<<"\""<<s<<"\", ";
	}
	cout<<endl;
	for (auto e: res)
		cout<<"\'"<<e<<"\', ";
	return 0;
}