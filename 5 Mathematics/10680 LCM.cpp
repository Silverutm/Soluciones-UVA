#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

ll _sieve_size;
bitset<1000010> bs;
vi primes;

void sieve(ll upperbound) 
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) 
    {
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back(i);
    } 
}
ll mod = 1000000000LL;
ll fastpow(ll x, ll n)
{
	int res=1;
	while (n)
	{
		if (n&1) res = res * x % mod;
		x = x * x %mod;
		n >>= 1;
	}
	return res;
}

ll f_t[1000005], f_p[1000005], f[1000005];

void primeFactors(ll N) 
{    
    ll z, n=N;
    int i;
    ll PF_idx = 0, PF = primes[PF_idx];     
    while (PF * PF <= N) 
    {
        f_p[PF] = 0;
        while (N % PF == 0) 
        { 
            N /= PF;
            ++f_p[PF];
        }
        z = f_p[PF] - f_t[PF];
        if (z>0)
        {
            f_t[PF] = f_p[PF];
            f[n] = f[n] * fastpow(PF, z);
            while(f[n]%10 == 0) f[n]/=10;
            f[n] %= mod;
        }


        PF = primes[++PF_idx];
    }
    if (N != 1)
    {
        f_p[N] =  1;        
        if (!f_t[N])
        {
            f_t[N] = 1;
            f[n] = f[n] * N;
            while(f[n]%10 == 0) f[n]/=10;
            f[n] %= mod;
        }
    }   
    return ;
}

int main()
{
    sieve(1000000);
    f[1] = 1; f[2] = 2; f[3] = 6;
    f_t[2] = 1; f_t[3] = 1;

    for (int i = 4; i< 1000001; ++i )
    {
        f[i] = f[i-1];
        primeFactors(i);
    }        
    
    ll n;
    while (scanf("%lld", &n) and n)    
        printf("%lld\n", f[n]%10);
    return 0;
}