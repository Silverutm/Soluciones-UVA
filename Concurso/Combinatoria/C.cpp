#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define tam 53

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



char mat[tam][tam];
int grado[tam], solitos, largos, dedos, visitado[tam], n;
bool posible;

bool busca(int u)
{
    if (grado[u]>2) return false;
    visitado[u] = 1;
    int yabusque = 0;
    for (int v=1; v<=n; ++v)
        if (visitado[v]==0 and mat[u][v]=='Y')
        {
            if (not busca(v))
                return false;
            yabusque=1;
        }
    
    if (grado[u] == 1)
        return true;
    if (not yabusque) return false;
}

int main()
{
	fact[0]=1;
	for (int i=1; i<= tam; ++i)
		fact[i] = fact[i-1] * i % mod;

	factreverso[tam]=fastpow( fact[tam] , mod-2);

	for (int i=tam-1; i>=0; --i)
		factreverso[i] = factreverso[i+1]*(i+1)%mod;

	
    cin>>n;
    int i, j;
    for (i=1; i<=n; ++i)        
        for (j=1; j<=n; ++j)
        {
            cin>>mat[i][j];
            //cout<<mat[i][j];
            if (mat[i][j] == 'Y')
                ++grado[i];
        }//cout<<grado[i]<<endl;}
    
    //cout<<endl;
    for (i=1; i<=n; ++i)
    {
        if (grado[i]==1 and !visitado[i])
        {
            posible = true;
            for (j=1; j<=n; ++j)
                if (mat[i][j]=='Y' and grado[j]==1)
                {
                    ++dedos;
                    visitado[i] = visitado[j] = 1;
                    posible = false;
                }
            if (posible and busca(i))
                ++largos;
        }
        else if (grado[i]==0)
        {
            ++solitos;
            visitado[i] = 1;
        }
    }
    ll w=1;
    if (dedos) w = w*dedos*2%mod;
    //else dedos =1;

    if (largos) w = w*largos*2%mod;
    //else largos=1;

    /*cout<<solitos<<" "<<dedos<<" "<<largos<<endl;
    for (j=1; j<=n; ++j)
        if (not visitado[j])
        {
            cout<<0<<endl;
            return 0;
        }*/
    for (int i=1; i<=n; ++i)
        if(not visitado[i])
        {
            cout<<0<<endl;
            return 0;
        }
    cout<<fastpow(2, largos + dedos)*fact[dedos+largos+ solitos]%mod<<endl;
	return 0;
}