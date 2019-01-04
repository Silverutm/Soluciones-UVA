#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
ll _sieve_size;
#define tam 1000005
bitset<1000010> bs;
vi primes;
int a[1000010], b[1000010];
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
    sieve(1000000);    

        
    int n;
    while (cin>>n and n)
    {
        for (int i=1; i<primes.size(); ++i)
            if ( bs[n - primes[i] ] )
            {
                cout<<n<<" = "<<primes[i]<<" + "<<n - primes[i]<<"\n";
                break;
            }
    }
    return 0;
}