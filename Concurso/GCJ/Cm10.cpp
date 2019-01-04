#include <iostream>
#include <cstdio>
#include <bitset> // compact STL for Sieve, better than vector<bool>!
#include <vector>
using namespace std;

long long _sieve_size; // ll is defined as: typedef long long ll;
bitset <1000010> bs; // 10^7 should be enough for most cases
vector <long long>  primes; // compact list of primes in form of vector<int>
long long isPrime(long long N) 
{ // a good enough deterministic prime tester
	//if (N <= _sieve_size) 
	//	return bs[N]; // O(1) for small primes
	for (int i = 0; i < (int)primes.size(); i++)
		if (N % primes[i] == 0) return primes[i];
	return 0LL; // it takes longer time if N is a large prime!
}
void sieve(long long upperbound)
{ // create list of primes in [0..upperbound]
	
	for (long long caos=5; caos<=1000000000000000000LL; caos+=2)
		if (isPrime(caos)==0LL) primes.push_back(caos);
	return;

	_sieve_size = upperbound + 1; // add 1 to include upperbound
	bs.set(); // set all bits to 1
	bs[0] = bs[1] = 0; // except index 0 and 1
	for (long long i = 2; i <= _sieve_size; i++)
		if (bs[i])
		{
			// cross out multiples of i starting from i * i!
			for (long long j = i * i; j <= _sieve_size; j += i) 
				bs[j] = 0;
			primes.push_back((int)i); // add this prime to the list of primes
		} 
} // call this method in main method
 // note: only work for N <= (last prime in vi "primes")^2
// inside int main()
long long t, n, j, s, k, i;
vector <long long> divisores;
bool convertir(int base)
{
	int pot;
	long long conversion=0LL, comodin=1;
	for (pot=0; pot<n; ++pot)
	{
		if ( s &(1<<pot) )
			conversion+=comodin;
		comodin*=base;
	}
	long long esp;
	if (  not( esp=isPrime(conversion) )   )
		return false;
	else divisores.push_back(esp);
	return true;
}


void imprimir()
{
	--k;	
	for (int pot=n-1; pot>=0; --pot)
		cout<<!!( s&(1<<pot) );
	for (auto d:divisores)
		cout<<" "<<d;
	cout<<endl;
	return ;
}

int main()
{
	sieve(1000000); // can go up to 10^7 (need few seconds)
	//printf("%d\n", isPrime(2147483647)); // 10-digits prime
	//printf("%d\n", isPrime(136117223861LL)); // not a prime, 104729*1299709
	int base;
	cin>>t;
	primes.push_back(2);
	primes.push_back(3);
	for (i=1; i<=t; ++i)
	{
		cin>>n>>k;
		cout<<"Case #"<<i<<":\n";
		s=0;
		s |= 1;
		s |= (1 << (n-1));
		//cout<<s<<endl;
		//return 0;
		for (; k; )
		{
			s+=2;
			//s |= (1 << (n-1));
			divisores.clear();
			for (base=2; base<=10 and convertir( base); ++base);
			if (base==11) imprimir();
		}
	}
	return 0;
}
