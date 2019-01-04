#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef vector <int> vi;
typedef long long ll;
typedef pair <int , int> ii;


int main()
{
	ll n;
	while(scanf("%lld", &n)  && n)
	{
		ll res = 0;
		ll k = 0;
		for (ll i = 1; ; ++i)
		{
			k =  i * i * i;
			if (k > n) break;
			if (n % k == 0) res++;

		}
		printf("%lld\n", res);
	}
	return 0;
}