#include <bits/stdc++.h>
#define pb push_back()
#define pair <int, int> ii;
using namespace std;
typedef long long ll;
typedef vector <int> vi;



ll n;

 // compact STL for Sieve, better than vector<bool>!
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
factors.push_back(0);
//ll res;
ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
while (PF * PF <= N) { // stop at sqrt(N); N can get smaller
while (N % PF == 0) 
{ N /= PF;if (factors[factors.size()-1]!=PF)  
		{n /= PF;
			n *= (PF -1);
} factors.push_back(PF);  
	
	} // remove PF
PF = primes[++PF_idx]; // only consider primes!
}
if (N != 1) {if (factors[factors.size()-1]!=N)  
		{n /= N;
			n *= (N -1);
}factors.push_back(N); }// special case if N is a prime
//cout<<n<<"  l"<<endl;
return factors; // if N does not fit in 32-bit integer and is a prime
}



int main()
{
	int t;
	sieve(10000000);
	cin>>t;
	while (t--)
	{
		cin>>n;
		primeFactors(n);
		cout<<n<<endl;
	}

}