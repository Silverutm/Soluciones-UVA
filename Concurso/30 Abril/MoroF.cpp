#include <bitset>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define tam 1000003
ll divsores[1000007];
vector <int> primos;
bitset <1000007> esprimo;

#define mod 987654321

void criba()
{
	esprimo.set();
	esprimo[0]=esprimo[1]=false;
	for (ll i=2; i<=tam; ++i)
		if (esprimo[i])
		{
			primos.push_back( (int)i );
			for (ll j=i*i; j<=tam; j+=i)
				esprimo[j]=false;

		}
}

ll div(int n)
{
	if ( divsores[n]!=-1 ) return divsores[n];
	int i=0;
	ll tot=1, factores, parcial;
	while (primos[i]<=n)
	{
		factores=primos[i];
		parcial=1;
		while ( factores<=n )
		{
			parcial+=n/factores;
			factores*= primos[i];
		}
		tot = tot* parcial%mod;
		++i;
		if (i==primos.size() ) break;
	}
	return divsores[n]=tot;
}


int main()
{
	int n, k;
	memset (divsores, -1, sizeof divsores);
	criba();
	while (cin>>n>>k)
	{
		ll res=(div(n)-div(k) +mod)%mod;
		cout<<res<<endl;
	}
	return 0;
}