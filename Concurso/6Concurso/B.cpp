#include <iostream>
using namespace std;
long long a, n, i;
int main()
{
	long long t, j;
	cin>>t;
	for (j=1; j<=t; ++j)
	{
		cin>>a;
		n=0;
		while (a%2==0)
		{
			++n;
			a /=2;
		}
		i=a;
		cout<<"Caso #"<<j<<": (2^"<<n<<")*"<<i<<endl;
	}
	return 0;
}