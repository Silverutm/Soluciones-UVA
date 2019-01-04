#include <bits/stdc++.h>
using namespace std;
#define tam 1000003
typedef vector <int> vi;
typedef long long ll;
ll _sieve_size;
bitset<1000010> bs;
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
/*if (N <= _sieve_size)*/ return bs[N];
// O(1) for small primes
for (int i = 0; i < (int)primes.size(); i++)
if (N % primes[i] == 0) return false;
return true;
// it takes longer time if N is a large prime!
}
int veces[tam];
void primeFactors(ll N) {
// remember: vi is vector<int>, ll is long long
vi factors;
//factors.push_back(1);
ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
ll el_N=N;
while (PF * PF <= N) {
// stop at sqrt(N); N can get smaller
	bool ya = false;
while (N % PF == 0) { N /= PF; if (not ya) ++veces[el_N]; ya=true; }
// remove PF
PF = primes[++PF_idx];
// only consider primes!
}
if (N != 1) ++veces[el_N]; //factors.push_back(N);
// special case if N is a prime
return;// factors;
// if N does not fit in 32-bit integer and is a prime
}
int n, x, y;
ll res, dos_mod[tam], ans[tam];
#define mod 1000000007
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	sieve(1000000);
	int i;
	for ( i = 2; i < tam; ++i)
		if (isPrime(i)) veces[i] = 1;
		else primeFactors(i);

	dos_mod[0] = 1;
	for ( i = 1; i < tam; ++i)
		dos_mod[i] = (dos_mod[i - 1] << 1) % mod;

	for ( y = 2; y < tam; ++y)
		ans[y] = (2*ans[y-1] + veces[y]*dos_mod[y-1] )%mod;
	while (cin>>n>>x>>y and n)
	{
		res = 0;
		y -= x;
		/*for ( i = 2; i <= y; ++i)
		{
			res += veces[i] * dos_mod[ y-1 ] % mod;
		}*/
		cout<<ans[y]<<"\n";
	}
	return 0;
}