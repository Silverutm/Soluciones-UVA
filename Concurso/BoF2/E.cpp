#include <bitset> // compact STL for Sieve, better than vector<bool>!
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
ll _sieve_size;
bitset<10000010> bs;
vi primes;
void sieve(ll upperbound) 
{
	_sieve_size = upperbound + 1;
	bs.set(); 
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) 
		if (bs[i]) 
		{
			for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
				primes.push_back((int)i);
		}
 }
bool isPrime(ll N)
{
	if (N <= _sieve_size) 
		return bs[N];
	for (int i = 0; i < (int)primes.size(); i++)
	if (N % primes[i] == 0) return false;
	return true; 
}
bool loes;
int i;
string n;
void revisa()
{
	int res=0;
	int j;
	for (j=i; j<n.size(); ++j)
	{
		res*=10;
		res+=n[j]-'0';
	}
	//cout<<res<<endl;
	loes = isPrime(res);
	return;
}

int main()
{
	sieve(10000000); 
	int t;
	
	cin>>t;
	while (t--)
	{
		cin >>n;
		loes=true;
		for (i=0; i<n.size() && loes; ++i)  revisa();
		if (loes) cout<<"SI\n";
		else cout<<"NO\n";
	}
	return 0;
}
