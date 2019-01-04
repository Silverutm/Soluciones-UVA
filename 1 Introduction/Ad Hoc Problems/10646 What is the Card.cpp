#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int t, x, i, y, caso;
	string s;
	vector <string> pila, mano;
	cin>>t;
	while (t--)
	{
		pila.clear();
		mano.clear();
		x=27;
		while (x--)
		{
			cin>>s;
			pila.push_back(s);
		}
		x=25;
		while (x--)
		{
			cin>>s;
			mano.push_back(s);
		}
		i=26;
		y=0;

		if ( pila[i][0]>='2' and pila[i][0]<='9' )
			x=pila[i][0]-'0';
		else x=10;
		y += x;
		i--;
		pila.pop_back();
		i-=10-x;
		for (int j=0; j<10-x; ++j)
			pila.pop_back();

		if ( pila[i][0]>='2' and pila[i][0]<='9' )
			x=pila[i][0]-'0';
		else x=10;
		y += x;
		i--;
		pila.pop_back();
		i-=10-x;
		for (int j=0; j<10-x; ++j)
			pila.pop_back();

		if ( pila[i][0]>='2' and pila[i][0]<='9' )
			x=pila[i][0]-'0';
		else x=10;
		y += x;
		i--;
		pila.pop_back();
		i-=10-x;
		for (int j=0; j<10-x; ++j)
			pila.pop_back();

		for (auto c:mano)
			pila.push_back(c);

		cout<<"Case "<<++caso<<": "<<pila[y-1]<<endl;
	}
	return 0;
}