#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define pb push_back
#define mod 1000000007
#define tam 1004

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

	
    int n, m, x, ant;    
    cin>>n>>m;
    
    for (int i=0; i<m; ++i)
    {
        cin>>x;
        arr[x] = 1;        
    }    
    ll res = fact[n - m];
    int cant = 0;
    bool laprimera, laultima;
    if (arr[1]) laprimera = true;
    if (arr[n]) laultima = true;
    int veces = 0, fina = 0, pri=0;
    for (int i=1; i<=n; ++i)
    {
        if (arr[i] == 1 or i==n)
        {
            if (cant!=0)
            {
                res = res * factreverso[i ==n ? cant+1:cant] % mod;
                fina = cant;
                if (!pri) pri = cant;
                ++veces;                
            }
            cant = 0;
        }
        else ++cant;
    }

    int z = n - m - veces;

    cout<<res<<endl<<veces<<endl;
    cout<<z<<endl;
    if (not laprimera or (veces == 1 and not laultima))
    {
        z -= pri - 1;
    }
    if (not laultima and veces!=1)
    {
        z -= fina - 1;
    }
    
    res = res * fastpow(2, z) % mod;
    cout<<res<<endl;
    
	return 0;
}