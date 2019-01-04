#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef vector <int> vi;
ll tam;
bitset<100010> bs;
vi primos;

void criba(ll lim) 
{
    tam = lim + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= tam; i++) 
    if (bs[i]) 
    {
        for (ll j = i * i; j <= tam; j += i) 
            bs[j] = 0;
        primos.pb((int)i);
    } 
}

ll suma(ll N) 
{
    ll ind = 0, PF = primos[ind], ans = 1, parcial; int i;

    while (PF * PF <= N) 
    {
        ll potencia = 0;
        while (N % PF == 0) 
        { 
            N /= PF; 
            potencia++; 
        }
        parcial = 1;
        for (i=0; i<=potencia; ++i)
            parcial *= PF;
        ans *= ( parcial -1 ) / (PF -1);
        PF = primos[++ind];
    }
    if (N != 1) ans *= (N*N - 1) / (N - 1); 
    return ans;
}

long countSum(vi numbers)
{
    criba(100000);    
    ll res = 0;

    for (int n:numbers)
    {
        while (not (n&1) ) n >>= 1;        
        res += suma(n);
    }
    return res;
}

int main()
{
    
    int n, a;
    vi v;
    cin>>n;
    while(n--)
    {
        cin>>a;
        v.pb(a);        
    }
    cout<<countSum(v)<<endl;
}

