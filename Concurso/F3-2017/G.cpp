#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define m 1000000007
ll gcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll r = gcd(b, a%b, y, x);
	y -= a/b*x;
	return r;
}

inline ll divmod(const ll &a, const ll &b)
{
	ll binv;
	ll y;	
	gcd(b, m, binv, y);

	binv = ((binv%m)+m)%m;

	return ( (a % m) * (binv % m) ) % m;
}

int main()
{
	int t;
	ll n, res, x;
	scanf("%d", &t);
	for (int caso = 1; caso <= t; ++caso)
	{
		scanf("%lld", &n);
		res = 0;
		if (n&1)
		{
			x = ((n + 1)>>1)%m;
			if ( x%m!=0 ) 
				res = divmod( ((7*x%m*x%m*x%m*x%m-3*x%m*x%m*x%m+m+2*x%m*x%m)%m+m)%m ,6);			
		}
		else
		{
			x = (n>>1)%m + 1;
			if ( x%m!=0 ) 
				res = divmod( ((7*x%m*x%m*x%m*x%m - 15*x%m*x%m*x%m+m +11*x%m*x%m-3*x%m+m)%m+m)%m ,6);
		}
		printf("Case #%d: %lld\n", caso, res);
	}
	return 0;
}