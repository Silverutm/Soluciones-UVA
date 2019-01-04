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

bool chido(int e)
{
	int copia = e;
	vi digitos;
	while (e)
	{
		if (e%10==0) return false;
		digitos.push_back(e%10);
		e /= 10;
	}
	int p = 0;
	int diez = 1;
	for (auto &d:digitos)
	{
		p += diez*d;
		diez *= 10;
		//p += d;
		if (!isPrime(p)) return false;
	}
	reverse(digitos.begin(), digitos.end());
	p = 0;
	diez = 1;
	for (auto &d:digitos)
	{
		p += diez*d;
		diez *= 10;
		//p += d;
		if (!isPrime(p)) return false;
	}
	return true;
}

int main()
{
	sieve(10000000);
	for(int i=10000002; i<=100000000; ++i)
		if (isPrime(i)) primes.push_back(i);
	for (auto &e:primes)
		if (chido(e))
			cout<<e<<", ";
	//for()

	return 0;
}