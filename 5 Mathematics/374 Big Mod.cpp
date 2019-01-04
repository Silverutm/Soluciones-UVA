#include <iostream>
using namespace std;
typedef long long ll;

ll fastpow(ll x, ll n, ll mod)
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
	ll x, y, n;
	while (cin>>x>>y>>n)
		cout<<fastpow(x, y, n)<<endl;
	return 0;
}