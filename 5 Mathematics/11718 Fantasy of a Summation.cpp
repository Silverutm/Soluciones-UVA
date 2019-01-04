#include <iostream>
using namespace std;
typedef long long ll;
ll mod;

ll fast_pow(ll x,ll n)
{
	ll res = 1;
	while (n)
	{
		if (n&1)
			res = res*x % mod;

		x = x*x % mod;
		n >>= 1;
	}
	return res;
}

int main()
{
	ll k, res, a, n, fp;
	int t;
	cin>>t;
	for (int caso = 1; caso <= t; ++caso)
	{
		cin>>n>>k>>mod;
		res = 0;
		fp = fast_pow( n, k-1 );
		while (n--)
		{
			cin>>a;
			res =(res + a ) % mod;
		}
		res = res * k % mod * fp % mod;


		cout<<"Case "<<caso<<": "<<res<<endl;
	}
	return 0;
}