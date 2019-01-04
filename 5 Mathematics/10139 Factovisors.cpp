#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;
ll _sieve_size;
ll n, m;
bitset<10000010> bs;
vi primes;
map<ll, ll> factors;

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

bool isPrime(ll N) 
{

    if (N <= _sieve_size) return bs[N];

    for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
    return true;

}


void primeFactors(ll N) 
{    
    ll PF_idx = 0, PF = primes[PF_idx]; 
    while (PF * PF <= N) 
    {
        while (N % PF == 0) { N /= PF; ++factors[PF]; }
        PF = primes[++PF_idx];
    }
    if (N != 1) ++factors[N];    
}

ll cuenta(ll k)
{
    ll r = k;
    ll res = 0;
    while ( n/k )
    {
        res += n/k;
        k *= r;
    }
    return res;
}

int main()
{
    sieve(10000000);
    bool posible;
    while(cin>>n>>m)
    {
        factors.clear();
        primeFactors(m);
        posible= true;
        for (auto &par:factors)
            if (par.second > cuenta(par.first) )
            {
                posible = false;
                break;
            }
        if (posible)
            cout<<m<<" divides "<<n <<"!\n";
        else cout<<m<<" does not divide "<<n<<"!\n";
    }
    
    return 0;
}