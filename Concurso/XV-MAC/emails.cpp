#include <iostream>
using namespace std;
int main()
{
	string email;
	bool ya=false;
	while (getline(cin, email))
	{
		if (email=="") continue;
		if ( ya ) cout<<", ";
		cout<<email;
		ya= true;
	}
	return 0;
}