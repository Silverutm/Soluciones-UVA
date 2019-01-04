#include <iostream>
using namespace std;
int main()
{
	int t, n, mitad, a, i;
	cin>>t;
	for (int caso = 1; caso <= t; ++caso)
	{
		cin>>n;
		mitad = n/2;
		for (i = 0; i <= mitad; ++i)
			cin>>a;
		cout<<"Case "<<caso<<": "<<a<<endl;
		for (; i < n; ++i)
			cin>>a;
	}
	return 0;
}