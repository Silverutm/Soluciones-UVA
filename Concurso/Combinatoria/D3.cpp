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

	
    int n, m, x;    
    cin>>n>>m;
    //if (n<1 or m<1 or m>1000 or n>1000) for(;;);
    memset(arr,0, sizeof arr);
    while (m--)
    {
        cin>>x;
        arr[x] = 1;
    }
    int cant=0;
    for (int i=1; i<=n; ++i)
        if (arr[i]==0) ++cant;

    ll res = fact[cant];
    int i = 0, j = n+1;
    while (arr[++i]!=1);
    res = res * factreverso[i - 1] % mod;
    while (arr[--j]!=1);
    res = res * factreverso[n - j] % mod;

    cant = 0;
    int todos = 0, veces = 0;
    for (; i<=j; ++i)
    {
        if (arr[i] == 1)
        {
            if (cant!=0)
            {
                res = res * factreverso[cant] % mod;                
                ++veces;                
            }
            cant = 0;
        }
        else
        {
            ++cant;
            ++todos;
        } 
    }
    if (veces == 0) {cout<<0<<endl;return 0;}
    res = res * fastpow(2, todos - veces) % mod;
    if (res<0) for(;;);
    cout<<res<<endl;
	return 0;
}