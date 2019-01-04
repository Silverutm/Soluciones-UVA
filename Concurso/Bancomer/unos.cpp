#include <iostream>
using namespace std;
int main()
{
	int contador=0, unos=0;
	string s;
	getline(cin, s);
	while (getline(cin, s))
	{
		if ( s[s.size()-1]=='1' ) ++unos;
		++contador;
	}
	cout<<contador<<endl;
	cout<<unos<<endl;
}