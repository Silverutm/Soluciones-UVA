#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 5001

using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;
int aristas[tam][tam], graficas[tam][tam], divisores[tam];
ll const mod = 1000000007;
void div()
{
	int i, j;
	for ( i = 1; i < tam; ++i)
		for ( j = (i<<1); j < tam; j+= i)
			++divisores[j];
}

ll fact[tam], factreverso[tam];
ll n_en_k(int n, int k)
{
	//if (n<k) return 0LL;
	ll res= fact[n];
	res = res*factreverso[k]%mod;
	res = res*factreverso[n-k]%mod;
	return res;
}

ll fastpow( ll a, ll n )
{
	ll res=1;
	while ( n )
	{
		if ( n&1 )
			res=res*a%mod;
		a = a*a%mod;
		n >>=1;
	}
	return res;
}

/*ll dp_aristas(int n, int k)
{
	ll &r = aristas[n][k];
	if (n == 1) return r = 0;
	if (r!=-1) return r;
	return r = (dp_aristas(n-1, k) + min(ll(k),divisores[n]) ) % mod;
}

ll dp_graficas(int n, int k)
{
	ll &r = graficas[n][k];
	if (r!=-1) return r;
	if (n==1) return r = 1;

	if (divisores[n]>k)
		r = fact[divisores[n]]*factreverso[k]%mod*factreverso[divisores[n]-k]%mod;
		//n_en_k(divisores[n], k);
	else r = 1;

	return r = r * dp_graficas(n-1, k) % mod;
}*/

void it_aristas()
{
	for (int k = 1, r; k < tam; ++k)
	{
		for (int n = 1; n < tam; ++n)
		{
			//if (n==1) { aristas[n][k] = 0; continue; }
			if (n==1) {graficas[n][k]=1; continue;}
			if (divisores[n]>k) r = fact[divisores[n]]*factreverso[k]%mod*factreverso[divisores[n]-k]%mod;
			//n_en_k(divisores[n], k);
			else r = 1;	
			graficas[n][k] = graficas[n-1][k]*r%mod;
			aristas[n][k] = (min(divisores[n], k) + aristas[n-1][k] )%mod;
		}
	}
}

void it_graficas()
{
	ll r;
	for (int k = 1; k < tam; ++k)
	{
		for (int n = 1; n < tam; ++n)
		{
			if (n==1) {graficas[n][k]=1; continue;}
			if (divisores[n]>k) r = n_en_k(divisores[n], k);
			else r = 1;
			graficas[n][k] = graficas[n-1][k]*r%mod;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	div();
	//memset(aristas, -1, sizeof aristas);
	//memset(graficas, -1, sizeof graficas);
	fact[0]=fact[1]=1;
	for (int i=2; i< tam; ++i)
		fact[i] = fact[i-1] * i % mod;

	//factreverso[tam]=fastpow( fact[tam] , mod - 2);

	for (int i=tam-1; i>=0; --i)
		factreverso[i] = fastpow( fact[i] , mod - 2);
		//factreverso[i+1]*(i+1)%mod;

	int t, n, k;
	ll a, g;
	//scanf("%d", &t);
	cin>>t;
	it_aristas();
	while (t--)
	{
		//scanf("%d %d", &n, &k);
		cin>>n>>k;
		//it_aristas();
		//it_graficas();
		//a = dp_aristas(n,k);
		//g = dp_graficas(n,k);
		//printf("%d %d\n", aristas[n][k], graficas[n][k]);
		cout<<aristas[n][k]<<' '<<graficas[n][k]<<'\n';
	}
	return 0;
}