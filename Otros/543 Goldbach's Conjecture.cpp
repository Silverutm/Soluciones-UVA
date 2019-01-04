#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
ll _sieve_size;
#define tam 1000005;
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
    for (int &u:primes)
    for (int &v:primes)
        if (not a[u + v])
        {
            a[u+v]  = u;
            b[u+v]  = v;
        }
        else if (b[u + v] - a[u + v] < v - u)
        {
            a[u+v]  = u;
            b[u+v]  = v;
        }
    int n;
    while (cin>>n and n)
        cout<<n<<" = "<<a[n]<<" + "<<b[n]<<"\n";
    return 0;
}