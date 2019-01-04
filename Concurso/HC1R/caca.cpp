#include <bits/stdc++.h>
#define s second
#define f first
#define mk make_pair
#define pb push_back
#define tam 2005
#define INF 10000000000000LL
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

ll mod =1000000007LL;
ll n, m, radio[tam], suma, mp, res, sp, espacios;

ll factorial[tam], fn_2;
map <ll, ll> mapa[tam];

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


ll divmod(const ll &a, const ll &b)
{
	ll binv;
	ll y;
	gcd(b, mod, binv, y);

	binv = ((binv%mod)+mod)%mod;

	return ( (a % mod) * (binv % mod) ) % mod;
}



int main()
{
	factorial[0]=1;
	for (ll i = 1; i < tam; ++i)
		factorial[i] = factorial[i-1] * i % mod;

	int t;
	cin>>t;
	for (int caso = 1; caso <= t; ++caso)
	{
		res = suma = 0LL;

		cin>>n>>m;
		for (int i = 0; i < n; ++i)
		{
			cin>>radio[i];
			suma += radio[i];
		}
		if (n == 1)
		{
			cout<<"Case #"<< caso <<": "<< m <<"\n";
			continue;
		}


		fn_2 = factorial[n-2];
		//suma de puntos, adentro y afuera
		// lo que ocupare
		sp =2*suma;// + radio[i] + radio[j];
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				//espacios
				mp = m;
				mp += radio[i] + radio[j] - 1;

				//sp

				espacios = mp - sp;
				//no cabe
				if (espacios<0) continue;

				if ( mapa[n][espacios] )
				{
					res = (res + mapa[n][espacios])%mod;
					continue;
				}

				ll parcial = 1;
				for (ll w = espacios+1; w <= espacios + n; ++w)
				{
					parcial = parcial * (w % mod ) % mod;
				}
				parcial = divmod( parcial, factorial[n]);
				//multiplicacion espacios+1 hasta espacios + circulos n
				//entre n factorial
				mapa[n][espacios] = 2 * parcial % mod * fn_2 % mod;
				res = res + mapa[n][espacios]; res = res % mod;
			}
		}
		cout<<"Case #"<< caso <<": "<< res <<"\n";
	}
	return 0;
}