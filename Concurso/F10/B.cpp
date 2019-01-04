#include <bits/stdc++.h>
#define pb emplace_back()
#define pair <int, int> ii;
#define MOD 1000000007LL
#define tam 500005
using namespace std;
typedef long long ll;
typedef vector <int > vi;
ll p;
int n;
ll arreglo[tam], mas1[tam], acumulado[tam];

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


inline ll restmod(const ll &a, const ll &b, const ll &m)
{
	return ( ( (a % m) - (b % m) ) + m ) % m;
}

inline ll divmod(const ll &a, const ll &b, const ll &m)
{
	ll binv;
	ll y;
	gcd(b, m, binv, y);

	binv = ((binv%m)+m)%m;

	return ( (a % m) * (binv % m) ) % m;
}


ll fastPow(ll x, ll n) {
	ll ret = 1;
	while (n) {
		if (n & 1) ret = ret*x%MOD;
		x = x*x%MOD;
		n >>= 1;
	}
	return ret;
}



int main()
{
	int a, b, q;
	ll kk;
	while ( scanf ("%d %lld", &n, &p)==2 )
	{
		ll res;

		for (int i = 1; i <= n; ++i)
			scanf("%lld", &arreglo[i]);
		scanf("%d", &q);
		mas1[0]=1;
		for (int i = 1; i <= n; ++i)
		{
			kk = fastPow(p, arreglo[i] );
			acumulado[i] = ( acumulado[i-1] * ( kk +1 )  )% MOD +  kk;
			acumulado[i] %= MOD;

			mas1[i] = ( mas1[i-1 ] * ( kk +1 ) ) % MOD;
		}
		
		//for (int i = 1; i <= n; ++i)
			
		while (q--)
		{
			scanf("%d %d", &a, &b);
			res = acumulado[b] - acumulado[a-1]*divmod( mas1[b], mas1[a-1], MOD  );
			res%= MOD ;
			res += MOD;
			res %=MOD;
			printf("%lld\n", res);

		}
	}
	return 0;
}