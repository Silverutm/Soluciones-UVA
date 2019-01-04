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
    //if (n==m) {cout<<0<<endl; return 0;}
    int mm=m;
    for (int i=0; i<m; ++i)
    {
        cin>>x;
        if (arr[x]) --mm;
        arr[x] = 1;
        
                
    }    
    ll res = fact[n - mm];
    arr[0] = arr[n+1] = 1;
    int cant = 0, veces = 0;
    for (int i=1; i<=n+1; ++i)
    {
        if (arr[i] == 1)
        {
            if (cant!=0)
            {
                res = res * factreverso[cant] % mod;
                //fina = cant;
                //if (!pri) pri = cant;
                ++veces;                
            }
            cant = 0;
        }
        else ++cant;
    }
    
    if (veces == 1)    
    {
        if ( arr[1]==1 and arr[n]==1 ) 
        {
            cant =0;
            for (int i=1; i<=n; ++i)
                if (arr[i]==0) ++cant;
            cout<<fastpow(2, cant - 1)<<endl;
        }
        else cout<<1<<endl;
        return 0;
    }
    if (veces==0) {cout<<1<<endl;return 0;}

    cant = 0; int i= 0;
    if (arr[1] != 1)
    {
        while(arr[++i]==0);
        cant = i - 1;
        --veces;
        //cout<<i-1<<"   ...."<<endl;
    }

    i=n+1;
    if (arr[n] != 1 )//and veces != 1)
    {
        while(arr[--i]==0);
        cant += n - i;
        //if (veces!=1)
            --veces;
        //cout<<n-i<<endl;
    }

    res = res*fastpow(2, max(0, n - mm - veces - cant));
    
    cout<<res<<endl;
    
	return 0;
}