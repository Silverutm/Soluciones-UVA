#include <iostream>
using namespace std;

int fastpow(int x, int n, int mod)
{
	int res=1;
	while (n)
	{
		if (n&1) res = res * x % mod;
		x = x * x %mod;
		n >>= 1;
	}
	return res;
}

int main()
{
	int c, x, y, n;
	cin>>c;
	while (c--)
	{
		cin>>x>>y>>n;
		cout<<fastpow(x, y, n)<<endl;
	}
	return 0;
}