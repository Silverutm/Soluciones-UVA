#include <bits/stdc++.h>
#define tam 10005
using namespace std;
typedef long long ll;
typedef vector <int> vi;
ll _sieve_size;

bitset<10010> bs;
vi primes;
int f[tam], ac[tam];
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
    return ;
}


int main()
{
    sieve(10000);
    //ac[0] = primes[0];
    //for (int i=1; i<primes.size(); ++i)
        //ac[i] = ac[i - 1] + primes[i];
    for (int i=0; i<primes.size(); ++i)
        ac[i + 1] = ac[i] + primes[i];
    for (int i=1; i<=primes.size(); ++i)
        for (int j=0; j<i; ++j)
            if ( ac[i] - ac[j] < tam)
                ++f[ ac[i] - ac[j] ];
    int n;
    while (cin>>n and n)
        cout<<f[n]<<"\n";
    return 0;
}