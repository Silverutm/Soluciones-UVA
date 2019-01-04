#include <iostream>
using namespace std;
typedef long long ll;

#define tam 1000003
#define mod 1000000007LL
ll factrial[tam+2];
ll factorialreverso[tam+2];

ll faspow(ll a, ll n)
{
	ll res=1;
	while (n)
	{
		if (n&1)
			res =res*a%mod;
		a = a*a%mod;
		n >>=1;
	}
	return res;
}

ll n_en_k(int n, int k)
{
	ll res=0;
	if (n<k) return res;
	res =factrial[n];
	res= res*factorialreverso[k]%mod;
	res= res*factorialreverso[n-k]%mod;
	return res;
}

int main()
{
	int n, m, t2, t1, i;
	ll res;
	factrial[0]=1;
	for (i=1; i<=tam; ++i)
		factrial[i]= factrial[i-1] * i % mod;
	factorialreverso[tam]=faspow( factrial[tam], mod-2 );

	for (i=tam-1; i>=0; --i)
		factorialreverso[i] = factorialreverso[i+1] * (i+1) % mod;

	while (cin>>n>>m>>t1>>t2)
	{
		res=0;
		for  (i=t1; i<=t2; ++i)
			res=( res + n_en_k( n-i , m-1)  )%mod;
		cout<<res<<endl;
	}

	return 0;
}