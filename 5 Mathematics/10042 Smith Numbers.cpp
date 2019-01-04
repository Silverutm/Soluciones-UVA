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

bool isPrime(ll N) 
{

    if (N <= _sieve_size) return bs[N];

    for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
    return true;

}


vi primeFactors(ll N) 
{

    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx]; 
    while (PF * PF <= N) 
    {

        while (N % PF == 0) { N /= PF; factors.push_back(PF); }

        PF = primes[++PF_idx];

    }
    if (N != 1) factors.push_back(N);

    return factors;
}
 int suma(ll a)
 {
     int res = 0;
     while (a)
     {
         res += a%10;
         a /= 10;
     }
     return res;
 }

int main()
{
    sieve(10000000);
    
    int t; ll i;
    cin>>t;
    while (t--)
    {
        cin>>i;
        for(++i; ; ++i)
            if (not isPrime(i))
            {
                ll n = i;
                auto pf = primeFactors(i);
                int s_i = suma(i), s_p = 0;
                for (auto e:pf) s_p += suma(e);
                if (s_i == s_p)
                {
                    cout<<i<<"\n";
                    break;
                }
            }
    }
    return 0;
}