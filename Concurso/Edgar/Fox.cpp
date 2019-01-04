#include <iostream>
#include <cstdio>
#include <vector>

#include <bitset> // compact STL for Sieve, better than vector<bool>!
using namespace std;

typedef long long ll;
typedef vector<int> vi;
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

vi primeFactors(ll N) { // remember: vi is vector<int>, ll is long long
vi factors;
ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
while (PF * PF <= N) { // stop at sqrt(N); N can get smaller
while (N % PF == 0) { N /= PF; factors.push_back(PF); } // remove PF
PF = primes[++PF_idx]; // only consider primes!
}
if (N != 1) factors.push_back(N); // special case if N is a prime
return factors; // if N does not fit in 32-bit integer and is a prime
}

bool isPrime(ll N) { // a good enough deterministic prime tester
if (N <= _sieve_size) return bs[N]; // O(1) for small primes
for (int i = 0; i < (int)primes.size(); i++)
if (N % primes[i] == 0) return false;
return true; // it takes longer time if N is a large prime!
}


bool matriz[1003][1003];
vector <vi> Lista;
int sig=3;
void inserta(int e)
{
	vi v;
	for (int i=0; i<e; ++i)
		v.push_back(sig++);
	Lista.push_back(v);
}

void revisar(long long n);
void meter(long long n);

vi inicio(1,1), fin(1,2);
void meter(long long n)
{
	Lista.clear();
	vi r = primeFactors(n);
	for (auto &e: r)
	{
		if ( isPrime(e) and n>300)
		{
			revisar(n/2);
			revisar(n/2+1);	
			return ;
		}
	}
	Lista.push_back(inicio);
	for (auto e: r)
		inserta(e);
	Lista.push_back(fin);
	for (int i=0; i<Lista.size()-1; ++i)
	{
		for (auto& e1:Lista[i])
			for (auto& e2:Lista[i+1])
				;//matriz[e1][e2]=matriz[e2][e1]=1;
	}
}

void revisar(long long n)
{
	if ( isPrime(n) and n>300)
	{
		cout<<"es primo "<<n<<endl;
		revisar(n/2);
		revisar(n/2+1);
	}
	else meter(n);
}


void matalo(long long n)
{
	if(isPrime(n))
	{
		printf("Es primo %d\n", n);
		matalo(n/2);
		matalo(n/2+1);
	}
	else cout<<"no es primo "<<n<<endl;
}

int main()
{
	long long n;
	sieve(10000000);
	cin>>n;
	matalo(n);
	//return 0;
	revisar(n);
	printf("%d\n",sig-1 );
	return 0;
	for (int i=1; i<sig; ++i, printf("\n"))
		for (int j=1; j<sig; ++j)
			if (matriz[i][j]) printf("Y");
			else printf("N");
	return 0;
}