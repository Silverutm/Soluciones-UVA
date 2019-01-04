#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <bitset>
#include <map>
#include <cmath>
#include <queue>
#define f first
#define s second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;

ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 should be enough for most cases
vi primes; // compact list of primes in form of vector<int>
void sieve(ll upperbound) { // create list of primes in [0..upperbound]
_sieve_size = upperbound + 1; // add 1 to include upperbound
bs.set(); // set all bits to 1
bs[0] = bs[1] = 0; // except index 0 and 1
for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
// cross out multiples of i starting from i * i!
for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
primes.push_back((int)i); // add this prime to the list of primes
} }

vvi Lista;

void primeFactors(ll N) 
{ // remember: vi is vector<int>, ll is long long
	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
	while (PF * PF <= N) 
	{ // stop at sqrt(N); N can get smaller
		factors.clear(); factors.pb(1);
		while (N % PF == 0) 
		{ 
			N /= PF; 
			factors.push_back( PF*factors[factors.size()-1] ); 
		} // remove PF
		Lista.pb(factors);
		PF = primes[++PF_idx]; // only consider primes!
	}
	if (N != 1) 
	{
		factors.clear(); factors.pb(1);
		factors.push_back(N); // special case if N is a prime
		Lista.pb(factors);
	}
	//return factors; // if N does not fit in 32-bit integer and is a prime
}

bool indices[14];
int total;
void revisar(int c)
{
	while (c)
	{
		if ( indices[c%10] )
		{
			++total;
			return;
		}
		c /= 10;
	}
}
void sacartodos(int i, int val)
{
	if (i==Lista.size() )
	{
		revisar(val);
		//cout<<val<<" val"<<endl;
		return;
	}
	for (auto e:Lista[i])
	{
		//cout<<e<<" e"<<endl;
		sacartodos(i+1, val * e);
	}
}

int main()
{
	sieve(10000000);
	int n, c;
	cin>>n;

	if (n==1) {cout<<1<<endl;return 0;}

	c=n;
	while (c)
	{
		indices[c%10]=1;
		c /= 10;
	}
	primeFactors(n);
	sacartodos(0, 1);
	cout<<total<<endl;
	return 0;
}