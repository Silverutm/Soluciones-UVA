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



int arr[tam];
int main()
{
	fact[0]=1;
	for (int i=1; i<= tam; ++i)
		fact[i] = fact[i-1] * i % mod;

	factreverso[tam]=fastpow( fact[tam] , mod-2);

	for (int i=tam-1; i>=0; --i)
		factreverso[i] = factreverso[i+1]*(i+1)%mod;

	
    int n, m, x;
    cin>>n>>m;
    while(m--)
    {
        cin>>x;
        arr[x] = 1;
    }
    arr[0] = 1; arr[n + 1] = 1;
    int huecos = 0;
    for (int i = 1; i<=n; ++i)
        if (arr[i - 1] == 1 and arr[i] == 0)
            ++huecos;

    int blancos = 0;
    for (int i = 1; i<=n; ++i)
        if (arr[i] == 0)
            ++blancos;

    ll res = fact[blancos];

    int tam_hueco = 0;
    for (int i = 1; i<=n+1; ++i)
        if (arr[i] == 0) ++tam_hueco;
        else 
        {
            res = res * factreverso[tam_hueco] % mod;
            tam_hueco = 0;
        }
    int i = 1, j = n;
    while(arr[i] == 0) ++i;
    while(arr[j] == 0) --j;

    tam_hueco = 0;
    for (int k = i; k<=j; ++k)
    {
        if (arr[k] == 0) ++tam_hueco;
        if (arr[k] == 1 and tam_hueco)
        {
            res = res * fastpow(2, tam_hueco - 1) % mod;
            tam_hueco = 0;
        }
    }

    cout<<res<<"\n";
	return 0;
}