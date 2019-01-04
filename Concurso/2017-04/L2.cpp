#include <bits/stdc++.h>
using namespace std;
#define tam 500007
typedef vector <int> vi;
typedef long long ll;
ll _sieve_size;
bitset<10000010> bs;
vi primes;
// compact STL for Sieve, better than vector<bool>!
// ll is defined as: typedef long long ll;
// 10^7 should be enough for most cases
// compact list of primes in form of vector<int>
void sieve(ll upperbound) {
// create list of primes in [0..upperbound]
_sieve_size = upperbound + 1;
// add 1 to include upperbound
bs.set();
// set all bits to 1
bs[0] = bs[1] = 0;
// except index 0 and 1
for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
// cross out multiples of i starting from i * i!
for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
primes.push_back((int)i);
// add this prime to the list of primes
} }

bool isPrime(ll N) {
// a good enough deterministic prime tester
if (N <= _sieve_size) return bs[N];
// O(1) for small primes
for (int i = 0; i < (int)primes.size(); i++)
if (N % primes[i] == 0) return false;
return true;
// it takes longer time if N is a large prime!
}

vi primeFactors11(ll N) {
// remember: vi is vector<int>, ll is long long
vi factors;
factors.push_back(1);
ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
while (PF * PF <= N) {
// stop at sqrt(N); N can get smaller
	bool ya = false;
while (N % PF == 0) { N /= PF; if (not ya) factors.push_back(PF); ya=true; }
// remove PF
PF = primes[++PF_idx];
// only consider primes!
}
if (N != 1) factors.push_back(N);
// special case if N is a prime
return factors;
// if N does not fit in 32-bit integer and is a prime
}

map<ll, int> veces;
void primeFactors(ll N) {
// remember: vi is vector<int>, ll is long long
vi factors;
ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
while (PF * PF <= N) {
// stop at sqrt(N); N can get smaller
while (N % PF == 0) { N /= PF; /*factors.push_back(PF);*/++veces[PF]; }
// remove PF
PF = primes[++PF_idx];
// only consider primes!
}
if (N != 1) /*factors.push_back(N);*/ ++veces[N];
// special case if N is a prime
return ;//factors;
// if N does not fit in 32-bit integer and is a prime
}


int main()
{
	sieve(10000000);
	/*for(int i=10000002; i<=100000000; ++i)
		if (isPrime(i)) primes.push_back(i);
	for (auto &e:primes)
		if (chido(e))
			cout<<e<<", ";*/
	//for()
	int t;
	ll n;
	cin>>t;
	while(t--)
	{
		veces.clear();
		cin>>n;
		/*auto fa = */primeFactors(n);
		//veces[1] = 1;

		ll p=n;
		for (auto &par:veces)
		{
			p =p*( par.first - 1)/par.first;
		}
		//printf("%lld %.4f\n", p, p/2.0f);
		cout<<p<<" "<<p/2<<".";
		if (p&1) cout<<"5000\n";
		else cout<<"0000\n";


	}
	return 0;
}