#include <iostream>
using namespace std;
long long n, m, res;

long long cuantos(long long n, long long m)
{
	if (n<8 or m < 0)
		return 0;
	return ( (n-8 + 2)/2 )*((m-8 + 2)/2 );
}

int main()
{
	bool c;
	while (cin>>n>>m>>c and n)
	{		
		if (c) cout<<cuantos(n,m) + cuantos(n-1,m-1)<<endl;
		else cout<<cuantos(n,m-1) + cuantos(n-1,m)<<endl;
	}
	return 0;
}