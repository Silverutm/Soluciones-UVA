#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int arra[500], arrb[500];
char i;
string r;

void agrega(int n)
{
	for (int j = 0; j < n; ++j)
		r.push_back( i );
}

int main()
{
	string a,b;
	while ( getline(cin, a) and getline(cin, b) )
	{
		memset(arra, 0, sizeof arra);
		memset(arrb, 0, sizeof arrb);
		r.clear();

		for (auto e: a)
			++arra[e];
		for (auto e: b)
			++arrb[e];

		for ( i = 'a'; i <= 'z'; ++i)
			agrega( min(arra[i], arrb[i]) );
		cout<<r<<endl;
	}
	return 0;
}