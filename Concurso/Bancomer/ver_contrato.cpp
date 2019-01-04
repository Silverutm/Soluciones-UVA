#include <iostream>
using namespace std;
int main()
{
	string contrato = "33775a4e9e7def29406c434041c2bb4684f06d5d";
	string s, tran, c;
	getline(cin, s);

	while ( getline(cin, tran, '|') )
	{
		getline(cin, c, '|');
		getline(cin,s);
		if ( c== contrato )
			cout<<s<<"\n";
	}
	return 0;
}