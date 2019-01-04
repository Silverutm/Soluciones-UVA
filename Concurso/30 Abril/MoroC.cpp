#include <iostream>

#define mod 1000000007
#define tam 100003
using namespace std;
typedef long long ll;

ll fact[100005], factreverso[100005];

ll n_en_k(int n, int k)
{
	if (n<k) return 0LL;
	ll res= fact[n];
	res = res*factreverso[k]%mod;
	res = res*factreverso[n-k]%mod;
	return res;
}


ll fastpow( ll a, ll n )
{
	ll res=1;
	while ( n )
	{
		if ( n&1 )
			res=res*a%mod;
		a = a*a%mod;
		n >>=1;
	}
	return res;
}


int main()
{
	int n, k, res;
	fact[0]=1;
	for (int i=1; i<= tam; ++i)
		fact[i] = fact[i-1] * i % mod;

	factreverso[tam]=fastpow( fact[tam] , mod-2);
	//for (int i=0; i<= tam; ++i)
		//factreverso[i]=fp;

	for (int i=tam-1; i>=0; --i)
		factreverso[i] = factreverso[i+1]*(i+1)%mod;

	while (cin>>n>>k)
	{
		res=n_en_k(n-1, k)%mod;
		res <<=1;
		res %=mod;
		cout<<res<<endl;
	}
	return 0;
}