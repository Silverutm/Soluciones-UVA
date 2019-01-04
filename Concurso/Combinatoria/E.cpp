#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define tam 1008

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

ll fact[tam + 5], factreverso[tam + 5];

ll n_en_k(int n, int k)
{
	if (n<k) return 0LL;
	ll res= fact[n];
	res = res*factreverso[k]%mod;
	res = res*factreverso[n-k]%mod;
	return res;
}




int main()
{
	fact[0]=1;
	for (int i=1; i<= tam; ++i)
		fact[i] = fact[i-1] * i % mod;

	factreverso[tam]=fastpow( fact[tam] , mod-2);

	for (int i=tam-1; i>=0; --i)
		factreverso[i] = factreverso[i+1]*(i+1)%mod;

	
    int n, k;
    cin>>n>>k;
    
    if (k==1)
    {
        cout<<(fact[n] - fact[n-1] + mod)%mod <<"\n";
        return 0;
    }
    ll res = 0LL;
    for (int i = 0; i<=k; ++i)
    {
        int signo = (i%2==0) ? 1:-1;
        res = (res + fact[n - i] * n_en_k(k, i) * signo % mod + mod) % mod;        
        //cout<<fact[n - i] * n_en_k(k, i) * signo<<"\n";
    }    
    cout<<res<<"\n";
    
	return 0;
}