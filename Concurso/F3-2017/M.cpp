#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 100005
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;
ll _sieve_size;
bitset<1000010> bs;
vi primes;
void sieve(ll upperbound) 
{

	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) 
	{
		for (ll j = i * i; j <= _sieve_size; j += i) 
			bs[j] = 0;
		primes.push_back((int)i);
	} 
}

ll suma_primeFactors(ll N) 
{
	//vi factors;
	ll res = 1, parcial;	
	ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve	
	while (PF * PF <= N) 
	{
		parcial = 1;		
		while (N % PF == 0) 
		{ 
			N /= PF; 
			parcial *=PF;
			//factors.push_back(PF); 
		}
		parcial = ( parcial*PF - 1 )/(PF-1);
		res *=parcial;

		PF = primes[++PF_idx];
	}
	if (N != 1) //factors.push_back(N);
	{
		res *= (N*N-1)/(N-1);
	}
	return res;
}

int main()
{
	sieve(1000000);
	int t;
	ll n, r;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld", &n);
		r = suma_primeFactors(n)-n;
		if (r == n) printf("perfect\n" );
		else if (r<n) printf("deficient\n");
		else printf("abundant\n");

	}
}