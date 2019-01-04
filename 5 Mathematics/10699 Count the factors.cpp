#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;
ll _sieve_size;
ll n;
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

int primeFactors(ll N) 
{    
    ll PF_idx = 0, PF = primes[PF_idx]; 
    int res = 0;
    while (PF * PF <= N) 
    {
        bool ya = false;
        while (N % PF == 0) { N /= PF; if (not ya)++res;ya=true; }
        PF = primes[++PF_idx];
    }
    if (N != 1) ++res;    
    return res;
}



int main()
{
    sieve(10000000);    
    while(cin>>n and n)
        cout<<n<<" : "<<primeFactors(n)<<"\n";
    return 0;
}