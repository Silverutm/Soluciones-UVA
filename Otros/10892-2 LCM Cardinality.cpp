#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

ll _sieve_size;
bitset<10000010> bs;
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
ll k_1, k, primos;
ll primeFactors(ll N) 
{            
    if (N==1) return 1;
    k_1 = k = 1; primos = -1;
    ll PF_idx = 0, PF = primes[PF_idx];     
    ll parcial;
    while (PF * PF <= N) 
    {        
        parcial = 0;
        if (N % PF == 0) ++primos;
        while (N % PF == 0) 
        { 
            N /= PF;
            ++parcial;    
        }        
        if (parcial)
        {
            k_1 *= parcial + 1;
            k *= parcial;
        }
        PF = primes[++PF_idx];
    }
    if (N != 1)
    {
        k_1 *= 2;
        ++primos;
    }      
    
    return k_1 + ((1LL<<primos) - 1) * k;
}

int main()
{
    sieve(10000000);
               
    ll n;
    while (scanf("%lld", &n) and n)    
        printf("%lld %lld\n", n, primeFactors(n) );
    return 0;
}