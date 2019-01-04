#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 5001
using namespace std;
typedef unsigned long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;

ll _sieve_size;
bitset<10020> bs;
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

vector <ll> potencias;
void primeFactors(ll N) 
{
	//vi factors;
	ll res = 1, parcial;	
	ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve	
	while (PF * PF <= N) 
	{
		parcial = 0;		
		while (N % PF == 0) 
		{ 
			N /= PF; 
			//parcial *=PF;
			++parcial;
			//factors.push_back(PF); 
		}
		//parcial = ( parcial*PF - 1 )/(PF-1);
		//res *=parcial;
		if (parcial)
			potencias.push_back(parcial);

		PF = primes[++PF_idx];
	}
	if (N != 1) //factors.push_back(N);
	{
		//res *= (N*N-1)/(N-1);
		potencias.push_back(1);
	}
	return ;
}

int main()
{
	sieve(10010);
	ll n;
	while(scanf("%lld", &n) and n)
	{
		potencias.clear();
		primeFactors(n);
		ll multi = 1;
		for (auto &e:potencias)
			multi = multi*(e+1);

		for (auto &e:potencias)
			e = multi*e>>1;

		ll res = 1;
		for (auto &e:potencias)
			res = res*(e+1);		

		printf("%lld\n", res);
	}
	return 0;
}